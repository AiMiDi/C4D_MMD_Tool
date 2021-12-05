#ifndef NETWORK_OAUTH_H__
#define NETWORK_OAUTH_H__

#include "maxon/datadictionary.h"
#include "maxon/interface.h"
#include "maxon/observable.h"
#include "maxon/observerobject.h"
#include "maxon/url.h"



namespace maxon
{

class NetworkOAuthSessionRef;

enum class OAUTHSIGNATUREMETHOD
{
	NONE,
	PLAINTEXT,
	HMAC_SHA1,
} MAXON_ENUM_LIST(OAUTHSIGNATUREMETHOD);

enum class OAUTHHTTPMETHOD
{
	NONE,
	GET,
	POST,
} MAXON_ENUM_LIST(OAUTHHTTPMETHOD);

enum class OAUTHERRORCODE
{
	NO_USERACCOUNT = 100,
	SERVICE_NOT_AVAILABLE = 101,
} MAXON_ENUM_LIST(OAUTHERRORCODE);
	
//----------------------------------------------------------------------------------------
/// UrlRedirectInterface can be used to pass browser url redirects into the NetworkOAuthSessionInterface::InitV2Session function.
/// InitV2Session will hook up to the ObserverTokenRedirect to catch all browser redirects.
/// The html browser needs to forward all url redirect events to that observable.
/// e.g. dialog->_redirectRef.ObserverTokenRedirect().Notify(nUrl) iferr_return;
//----------------------------------------------------------------------------------------
class UrlRedirectInterface : MAXON_INTERFACE_BASES(ObserverObjectInterface)
{
	MAXON_INTERFACE(UrlRedirectInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.urlredirect");

public:
	MAXON_OBSERVABLE(Result<void>, ObserverTokenRedirect, (const Url& url, Bool hasError), ObservableCombinerRunAllComponent);
};

class UrlRedirectRef;

MAXON_DECLARATION(Class<UrlRedirectRef>, UrlRedirectClass, "net.maxon.class.urlredirectclass");

//----------------------------------------------------------------------------------------
/// OAuth helps to connect to services using this protocol (http://en.wikipedia.org/wiki/OAuth)
/// OAuth is used by a lot of APIs to deliver web based content (e.g. dropbox, google, twitter...)
/// Supported are OAuth1 and OAuth2.
/// Here is an prototype how to use the class functions.
/* @code
	CString appKey = "abcdefg"_cs;		// providers app key
	CString appSecret = "xyz..."_cs;	// providers app secret
	String accountDef = "123456"_s;	// user account id (or empty to login)

	NetworkOAuthSessionRef oauthSession = NetworkOAuthSessionRef::Create() iferr_return;
	account = oauthSession.InitV2Session(Url("https://api.dropbox.com/1/oauth2/authorize"_s), Url("https://api.dropbox.com/1/oauth2/token"_s),
		accountDef, appKey, appSecret, false,
		[](const NetworkOAuthSessionRef& session, const Url& url) -> Result<void>
		{
			return url.IoShowInOS(IOSHOWINOSFLAGS::OPEN_IN_EXPLORER);
		},
		[](const NetworkOAuthSessionRef& session) -> Result<String>
		{
			iferr_scope;
			DataDictionary dropboxInfo = session.ReadJson(Url("https://api.dropbox.com/1/account/info"_s), OAUTHSIGNATUREMETHOD::HMAC_SHA1, OAUTHHTTPMETHOD::GET) iferr_return;
			Int64 uid = dropboxInfo.Get<Int64>("uid"_s) iferr_return;
			return String::IntToString(uid);
		}) iferr_return;

	// send any command and receive the json answer:
	DataDictionary dropboxInfo = oauthSession.ReadJson(Url("https://api.dropbox.com/1/account/info"_s), OAUTHSIGNATUREMETHOD::HMAC_SHA1, OAUTHHTTPMETHOD::GET) iferr_return;

	// or sign any url and do your own request
	Url signedUrl = SignUrl(Url("http://www.maxon.de"_s), OAUTHSIGNATUREMETHOD::HMAC_SHA1, OAUTHHTTPMETHOD::GET) iferr_return;
	InputStreamRef stream = signedUrl.OpenInputStream() iferr_return;
	stream.Read(...) iferr_return;
@endcode
*/
//----------------------------------------------------------------------------------------
class NetworkOAuthSessionInterface
{
	MAXON_INTERFACE_NONVIRTUAL(NetworkOAuthSessionInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.networkoauthsession");
public:
	static MAXON_METHOD NetworkOAuthSessionInterface* Alloc(MAXON_SOURCE_LOCATION_DECLARATION);

	//----------------------------------------------------------------------------------------
	/// Starts a OAuth1 session. The first time (or if forceReapprovement is true) the user will be asked for credentials to access the service.
	/// @param[in] service						Service provider to connect with (e.g. "https://api.dropbox.com/1/oauth"). This id will be used to store the access keys together with the account.
	/// @param[in] account						Account to connect with. Depending on the service provider this can be the mail address or name.
	/// 															This value is used to store the private access tokens. Leave blank to create a new login.
	/// 															If the String was empty check the return value for the newly created account name.
	/// @param[in] appKey							Application Key from the provider.
	/// @param[in] appSecret					Application Secret from the provider.
	/// @param[in] signatureMethod		Signature method to sign with. OAUTHHTTPMETHOD::PLAINTEXT should only be used for non ssl connections.
	/// 															This method will be used for all url signings.
	/// @param[in] httpMethod					Http method to sign with.
	/// @param[in] forceReapprovement	Set to true to delete the old cached tokens and ask the user for new approval on the web side of the provide.
	/// @param[in] askForApproval			Optional callback to ask the user for approval of the a new session token. Usually a web browser opens the url where the user needs to click "Accept".
	/// 															Set to nullptr if you want the standard behavior "url.IoShowInOS(IOSHOWINOSFLAGS::OPEN_IN_EXPLORER)".
	/// 															This callback is only triggered if there is no valid session token found.
	/// @param[in] verifyAccountName	Callback to verify the stored token and retrieve the account name. This callback is triggered on the first connect.
	/// @return												Returns the account name delivered by the provider.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<String> InitV1Session(const Url& service, const String& account, const CString& appKey, const CString& appSecret,
																						OAUTHSIGNATUREMETHOD signatureMethod, OAUTHHTTPMETHOD httpMethod, Bool forceReapprovement,
																						const Delegate<Result<void>(const NetworkOAuthSessionRef& session, const Url& url)>& askForApproval,
																						const Delegate<Result<String>(const NetworkOAuthSessionRef& session)>& verifyAccountName);

	//----------------------------------------------------------------------------------------
	/// Starts a OAuth2 session. The first time (or if forceReapprovement is true) the user will be asked for credentials to access the service.
	/// @param[in] authUrl						Https://accounts.google.com/o/oauth2/auth.
	/// @param[in] tokenUrl						Https://accounts.google.com/o/oauth2/token.
	/// @param[in] account						Account to connect with. Depending on the service provider this can be the mail address or name.
	/// 															This value is used to store the private access tokens. Leave blank to create a new login.
	/// 															If the String was empty check the return value for the newly created account name.
	/// @param[in] appKey							Application Key from the provider.
	/// @param[in] appSecret					Application Secret from the provider.
	/// @param[in] forceReapprovement	Set to true to delete the old cached tokens and ask the user for new approval.
	/// @param[in] allowRedirectServer	True if the application should run a local server to catch the redirect. If false the server-less method can be used to catch the browser redirects directly.
	/// @param[in] redirectRef				Optional parameter server-less authentication (see UrlRedirectInterface).
	/// @param[in] askForApproval			Optional callback to ask the user for approval of the a new session token. Usually a web browser opens the url where the user needs to click "Accept".
	/// 															Set to nullptr if you want the standard behavior "url.IoShowInOS(IOSHOWINOSFLAGS::OPEN_IN_EXPLORER)".
	/// 															This callback is only triggered if there is no valid session token found.
	/// @param[in] verifyAccountName	Callback to verify the stored token and retrieve the account name. This callback is triggered on the first connect.
	/// @return												Returns the account name delivered by the provider.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<String> InitV2Session(const Url& authUrl, const Url& tokenUrl, const Url& redirectUrl, const String& account,
		const CString& appKey, const CString& appSecret, const CString& scope, Bool forceReapprovement, Bool allowRedirectServer,
		const UrlRedirectRef& redirectRef, const Delegate<Result<void>(const NetworkOAuthSessionRef& session, const Url& url)>& askForApproval,
		const Delegate<Result<String>(const NetworkOAuthSessionRef& session, const DataDictionary& response)>& verifyAccountName);

	//----------------------------------------------------------------------------------------
	/// Starts a OAuth2 session with the "Resource Owner Password Grant" method. This is less secure because the user name and password needs
	/// to be entered in the code and there is no redirect url where the server can send the result back to the verified source.
	/// @param[in] tokenUrl						Url to the toke url. this generates a http post to get the oauth access token.
	/// @param[in] userName						User name to login with.
	/// @param[in] password						Password for the given username.
	/// @param[in] account						Account to connect with. Depending on the service provider this can be the mail address or name.
	/// 															This value is used to store the private access tokens. Leave blank to create a new login.
	/// 															If the String was empty check the return value for the newly created account name.
	/// @param[in] appKey							Application Key from the provider.
	/// @param[in] appSecret					Application Secret from the provider.
	/// @param[in] verifyAccountName	Callback to verify the stored token and retrieve the account name. This callback is triggered on the first connect.
	/// @return												Returns the account name delivered by the provider.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<String> InitV2SessionWithResourceOwnerPasswordGrant(const Url& tokenUrl, const String& userName,
		const String& password, const String& account, const CString& appKey, const CString& appSecret, const CString& scope,
		const Delegate<Result<String>(const NetworkOAuthSessionRef& session, const DataDictionary& response)>& verifyAccountName);

	//----------------------------------------------------------------------------------------
	/// Starts a OAuth2 session with the "Refresh Token Grant" method. First the access token will be tried, if it's expired the refresh token
	/// will be used to generate a new access token.
	/// @param[in] tokenUrl						Url to the toke url. this generates a http post to get the oauth access token.
	/// @param[in] refreshToken				OAuth2.0 refresh token from the last session.
	/// @param[in] accessToken				OAuth2.0 access token from the last session.
	/// @param[in] appKey							Application Key from the provider.
	/// @param[in] appSecret					Application Secret from the provider.
	/// @param[in] verifyAccountName	Callback to verify the stored token and retrieve the account name. This callback is triggered on the
	/// first connect.
	/// @return												Returns the account name delivered by the provider.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<String> InitV2SessionWithRefreshOrAccessToken(const Url& tokenUrl, const CString& refreshToken,
		const CString& accessToken, const CString& appKey, const CString& appSecret, const CString& scope,
		const Delegate<Result<String>(const NetworkOAuthSessionRef& session, const DataDictionary& response)>& verifyAccountName);

	//----------------------------------------------------------------------------------------
	/// Signs a Url with the authentication tokens using the selected methods.
	/// @param[in] url								Url to be signed.
	/// @param[in] httpMethod					Http method to sign with.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Url> SignUrl(const Url& url, OAUTHHTTPMETHOD httpMethod) const;

	//----------------------------------------------------------------------------------------
	/// Signs and reads a given url directly into a json dictionary.
	/// @param[in] url								Url to be signed and read.
	/// @param[in] httpMethod					Http method to load the file.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<BaseArray<DataDictionary>> ReadJson(const Url& url, OAUTHHTTPMETHOD httpMethod, const StringDecodingRef& stringDecoding) const;

	//----------------------------------------------------------------------------------------
	/// Signs and reads a given url directly into a json dictionary.
	/// @param[in] url								Url to be signed and read.
	/// @param[in] httpMethod					Http method to load the file.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<BaseArray<DataDictionary>> ReadJWT(const Url& url, OAUTHHTTPMETHOD httpMethod,
		const StringDecodingRef& stringDecoding, const Block<const Char>& publicKey, BaseArray<Char>* originalToken) const;

	//----------------------------------------------------------------------------------------
	/// Returns the auth version used by this session. The protocol version can be 1 or 2.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetAuthVersion() const;

	//----------------------------------------------------------------------------------------
	/// Returns the user account id connected to this session.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String GetAccount() const;

	//----------------------------------------------------------------------------------------
	/// GetOAuthToken returns the OAuth token to access the resource.
	/// @return												Token string on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CString GetAccessToken() const;

	//----------------------------------------------------------------------------------------
	/// GetOAuthToken returns the OAuth token to access the resource.
	/// @return												Token string on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CString GetRefreshToken() const;

	//----------------------------------------------------------------------------------------
	/// Returns the url where the login token is stored.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Url> GetOAuthTokenUrl(const String& account) const;
};

#include "network_oauth1.hxx"
#include "network_oauth2.hxx"

}

#endif // NETWORK_OAUTH_H__
