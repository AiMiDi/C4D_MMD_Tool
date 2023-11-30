#ifndef ASSET_COMMAND_H__
#define ASSET_COMMAND_H__

#include "maxon/assets.h"
#include "maxon/delegate.h"

namespace maxon
{

class CommandAsset;

/// @addtogroup COMMAND_ASSET_STATE
/// @ingroup group_enumeration
/// @{
enum class COMMAND_ASSET_STATE
{
	NONE				= 0,				///< The command asset state is not defined.
	ENABLED			= (1 << 0), ///< The command asset is enabled.
	CHECKED			= (1 << 1), ///< The command asset is checkd.
	HIDDEN			= (1 << 2), ///< The command asset is hidden.
	HAS_OPTIONS	= (1 << 3), ///< The command asset has additional options.
} MAXON_ENUM_FLAGS(COMMAND_ASSET_STATE);
/// @}

//----------------------------------------------------------------------------------------
/// CommandAssetInterface extends the AssetInterface to deal with command assets.
//----------------------------------------------------------------------------------------
class CommandAssetInterface : MAXON_INTERFACE_BASES(AssetInterface)
{
	MAXON_INTERFACE(CommandAssetInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.commandasset");

public:
	static MAXON_METHOD Result<CommandAsset> Create();

	//----------------------------------------------------------------------------------------
	/// Executes the command asset. @see ASSETMETADATA::AssetCommandExecuteDelegate.
	/// @param[in] commandAsset				The command asset.
	/// @param[in] withOptions				If command has options (@ref COMMAND_ASSET_STATE::HAS_OPTION), set to @formatConstant{true} to show the options dialog before executing the command asset.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> Execute(const AssetDescription& commandAsset, Bool withOptions);

	//----------------------------------------------------------------------------------------
	/// Queries the command asset state. @see ASSETMETADATA::AssetCommandQueryStateDelegate and @enumerateEnum{COMMAND_ASSET_STATE}.
	/// @param[in] commandAsset				The command asset.
	/// @return                       The state of the command asset. @enumerateEnum{COMMAND_ASSET_STATE}.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<COMMAND_ASSET_STATE> QueryState(const AssetDescription& commandAsset);

	/// Undefined legacy command ID for @ref CommandAssetInterface::GetLegacyId.
	static constexpr Int LEGACY_ID_UNDEF = -1;

	// Returns LEGACY_ID_UNDEF if is unset (i.e. not a legacy command).
	static MAXON_METHOD Result<Int> GetLegacyId(const AssetDescription& commandAsset);

	//----------------------------------------------------------------------------------------
	/// Gets the command asset scopes, e.g. @ref ASSETMETADATA::CommandScopeMesh.
	/// @param[in] commandAsset				The command asset.
	/// @return                       Array with command scope IDs.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Array<Id>> GetCommandScopes(const AssetDescription& commandAsset);

	//----------------------------------------------------------------------------------------
	/// Adds the @formatParam{scope} into the @formatParam{scopeArray}.
	/// @param[in] scope							The command asset scope ID.
	/// @param[in, out] scopeArray		Array with scope IDs to ad the scope to.
	/// @return                       @formatConstant{true} if the scope has been successfully added (it didn't exists in @formatParam{scopeArray}), @formatConstant{false} if the @formatParam{scope} already exists in the @formatParam{scopeArray}.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Bool> AddCommandScope(const Id& scope, Array<Id>& scopeArray);

	//----------------------------------------------------------------------------------------
	/// Removes the @formatParam{scope} out of the @formatParam{scopeArray}.
	/// @param[in] scope							The command asset scope ID.
	/// @param[in, out] scopeArray		Array with scope IDs to erase the scope from.
	/// @return                       @formatConstant{true} if the scope has been successfully removed (it existed in @formatParam{scopeArray}), @formatConstant{false} if the @formatParam{scope} wasn't removed because @formatParam{scopeArray} doesn't contain it.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Bool> EraseCommandScope(const Id& scope, Array<Id>& scopeArray);

	//----------------------------------------------------------------------------------------
	/// Stores the @formatParam{scopeArray} into the @formatParam{commandAsset} metadata in the built-in database in a persistent way.
	/// @param[in] commandAsset				The command asset.
	/// @param[in] scopeArray					Array with scope IDs to be stored.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> StoreCommandScopes(const AssetDescription& commandAsset, Array<Id>&& scopeArray);

	//----------------------------------------------------------------------------------------
	/// Checks whether @formatParam{commandAsset} has the @formatParam{scope} assigned.
	/// @param[in] commandAsset				The command asset.
	/// @param[in] scope							The Scope ID to check.
	/// @return                       @trueIfOtherwiseFalse{@formatParam{commandAsset} contains the @formatParam{scope}}
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Bool> ContainsCommandScope(const AssetDescription& commandAsset, const Id& scope);

	//----------------------------------------------------------------------------------------
	/// Gets an array with all the names the @formatP of the scopes contained inChecks whether @formatParam{commandAsset} has the @formatParam{scope} assigned.
	/// @param[in] commandAsset				The command asset.
	/// @return                       Array with scope names.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<BaseArray<String>> GetCommandScopeNames(const AssetDescription& commandAsset);

	//----------------------------------------------------------------------------------------
	/// Gets the name of a command scope.
	/// @param[in] scope							The command asset scope.
	/// @return                       The scope name.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD String GetCommandScopeName(const Id& scope);

	//----------------------------------------------------------------------------------------
	/// Gets the command asset type, e.g. @ref ASSETMETADATA::CommandTypeCommand
	/// @param[in] commandAsset				The command asset.
	/// @return                       The command asset type.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Id> GetCommandType(const AssetDescription& commandAsset);

	//----------------------------------------------------------------------------------------
	/// Gets the name of a command type.
	/// @param[in] commandType				The command asset type.
	/// @param[in] repository					The asset repository.
	/// @return                       The command type name.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<String> GetCommandTypeName(const Id& commandType, const AssetRepositoryRef& repository);

	//----------------------------------------------------------------------------------------
	/// Checks if @formatParam{commandAsset} is of type Object, e.g. @ref ASSETMETADATA::CommandTypeObjectEffector.
	/// @param[in] commandAsset				The command asset.
	/// @return                       @trueIfOtherwiseFalse{@formatParam{commandAsset} is of type Object}
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool AssetIsObjectCommandType(const AssetDescription& commandAsset);

	//----------------------------------------------------------------------------------------
	/// Checks if @formatParam{commandType} is of type Object, e.g. @ref ASSETMETADATA::CommandTypeObjectEffector.
	/// @param[in] commandType				The command type.
	/// @return                       @trueIfOtherwiseFalse{@formatParam{commandType} is of type Object}
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool IsObjectCommandType(const Id& commandType);

	//----------------------------------------------------------------------------------------
	/// Registers an array of @formatParam{scopes} for a legacy @formatParam{commandId}.
	/// @param[in] commandId					The legacy command ID.
	/// @param[in] scopes							The array with the scopes to assign to legacy command ID.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> RegisterLegacyCommandScopes(Int32 commandId, const BaseArray<Id>& scopes);

	//----------------------------------------------------------------------------------------
	/// Gets the scopes registered to the legacy @formatParam{commandId}.
	/// @param[in] commandId					The legacy command ID.
	/// @return                       The array with the scopes assigned to legacy command ID
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<BaseArray<Id>> GetRegisteredLegacyCommandScopes(Int32 commandId);

	//----------------------------------------------------------------------------------------
	/// Registers a command @formatParam{type} for a legacy @formatParam{commandId}, e.g. @ref ASSETMETADATA::CommandTypeObjectField.
	/// @param[in] commandId					The legacy command ID.
	/// @param[in] type								The command type to assign to @formatParam{commandId}.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> RegisterLegacyCommandType(Int32 commandId, const Id& type);

	//----------------------------------------------------------------------------------------
	/// Gets the type registered to the legacy @formatParam{commandId}, e.g. @ref ASSETMETADATA::CommandTypeObjectField.
	/// @param[in] commandId					The legacy command ID.
	/// @return                       The command type assigned to @formatParam{commandId}.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Id GetRegisteredLegacyCommandType(Int32 commandId);
};

namespace ASSETMETADATA
{
	/// The command asset query state delegate. @see @enumerateEnum{COMMAND_ASSET_STATE}
	using AssetCommandQueryStateDelegate = Delegate<Result<COMMAND_ASSET_STATE>()>;
	MAXON_ATTRIBUTE(AssetCommandQueryStateDelegate, CommandQueryState, "net.maxon.asset.command.metadata.querystate");

	/// The command asset execute delegate.
	using AssetCommandExecuteDelegate = Delegate<Result<void>(Bool withOptions)>;
	MAXON_ATTRIBUTE(AssetCommandExecuteDelegate, CommandExecute, "net.maxon.asset.command.metadata.execute");

	/// The command asset help.
	MAXON_ATTRIBUTE(String,	CommandHelp,			 	"net.maxon.asset.command.metadata.help");

	/// The command asset shortcuts.
	MAXON_ATTRIBUTE(String,	CommandShortcuts,	 	"net.maxon.asset.command.metadata.shortcuts");

	/// The command asset legacy ID.
	MAXON_ATTRIBUTE(Int,		CommandLegacyId,	 	"net.maxon.asset.command.metadata.legacyid");

	/// The command asset legacy scope.
	MAXON_ATTRIBUTE(String,	CommandLegacyScope,	"net.maxon.asset.command.metadata.legacyscope");

	/// Sets the command asset hidden state.
	MAXON_ATTRIBUTE(Bool,		HiddenCommand,			"net.maxon.asset.command.metadata.hidden");

	/// Array with command scope IDs. @see CommandAssetInterface::GetCommandScopes, @see CommandAssetInterface::AddCommandScope, @see CommandAssetInterface::EraseCommandScope, @see CommandAssetInterface::StoreCommandScopes, @see CommandAssetInterface::ContainsCommandScope, @see CommandAssetInterface::GetCommandScopeNames and @see CommandAssetInterface::GetCommandScopeName
	MAXON_ATTRIBUTE(Array<Id>, CommandScopes,	"net.maxon.asset.command.metadata.scopes");

	MAXON_INTERNED_ID("net.maxon.asset.command.type.command",		 			 CommandTypeCommand);					///< General command.
	MAXON_INTERNED_ID("net.maxon.asset.command.type.hotkey",			 		 CommandTypeHotkey);					///< Hotkey command.
	MAXON_INTERNED_ID("net.maxon.asset.command.type.tool",						 CommandTypeTool);						///< Tool command.
	MAXON_INTERNED_ID("net.maxon.asset.command.type.object.generator", CommandTypeObjectGenerator);	///< Generator Object command.
	MAXON_INTERNED_ID("net.maxon.asset.command.type.object.deformer",	 CommandTypeObjectDeformer);	///< Deformer Object command.
	MAXON_INTERNED_ID("net.maxon.asset.command.type.object.effector",	 CommandTypeObjectEffector);	///< Effector Object command.
	MAXON_INTERNED_ID("net.maxon.asset.command.type.object.force",		 CommandTypeObjectForce);			///< Force Object command.
	MAXON_INTERNED_ID("net.maxon.asset.command.type.object.filter",		 CommandTypeObjectFilter);		///< Filter Object command.
	MAXON_INTERNED_ID("net.maxon.asset.command.type.object.primitive", CommandTypeObjectPrimitive);	///< Primitive Object command.
	MAXON_INTERNED_ID("net.maxon.asset.command.type.object.field",		 CommandTypeObjectField);			///< Field Object command.
	MAXON_INTERNED_ID("net.maxon.asset.command.type.object.scene",		 CommandTypeObjectScene);			///< Scene Object command.
	MAXON_INTERNED_ID("net.maxon.asset.command.type.object.other",		 CommandTypeObjectOther);			///< Other Object command.
	MAXON_INTERNED_ID("net.maxon.asset.command.type.tag",				 			 CommandTypeTag);							///< Tag command.
	MAXON_INTERNED_ID("net.maxon.asset.command.type.script",		 			 CommandTypeScript);					///< Script command.
	MAXON_INTERNED_ID("net.maxon.asset.command.type.mode",			 			 CommandTypeMode);						///< Mode command.
	MAXON_INTERNED_ID("net.maxon.asset.command.type.manager",		 			 CommandTypeManager);					///< Manager command.

	MAXON_INTERNED_ID("net.maxon.asset.command.scope.mesh",					CommandScopeMesh);					///< Scope for polygon mesh related items.
	MAXON_INTERNED_ID("net.maxon.asset.command.scope.model",				CommandScopeModel);					///< Scope for model related items.
	MAXON_INTERNED_ID("net.maxon.asset.command.scope.spline",				CommandScopeSpline);				///< Scope for spline related items.
	MAXON_INTERNED_ID("net.maxon.asset.command.scope.sculpting",		CommandScopeSculpting);			///< Scope for sculpting related items. Sculptbrushes, Sculpt modules.
	MAXON_INTERNED_ID("net.maxon.asset.command.scope.painting",			CommandScopePainting);			///< Scope for paiting and BodyPaint related items.
	MAXON_INTERNED_ID("net.maxon.asset.command.scope.uvs",					CommandScopeUVS);						///< Scope for UV related items.
	MAXON_INTERNED_ID("net.maxon.asset.command.scope.rigging",			CommandScopeRigging);				///< Scope for rigging related items. Mocca, Character Animation module.
	MAXON_INTERNED_ID("net.maxon.asset.command.scope.exchange",			CommandScopeExchange);			///< Scope for Exchange related items. GoZ, glTF, USD, Interop, Collada, Alembic, etc.
	MAXON_INTERNED_ID("net.maxon.asset.command.scope.materials",		CommandScopeMaterials);			///< Scope for Material related items.
	MAXON_INTERNED_ID("net.maxon.asset.command.scope.nodes",				CommandScopeNodes);					///< Scope for Node Editor related items. Nodeeditor2, Nbo
	MAXON_INTERNED_ID("net.maxon.asset.command.scope.particles",		CommandScopeParticles);			///< Scope for simple particles related items.
	MAXON_INTERNED_ID("net.maxon.asset.command.scope.cloth",				CommandScopeCloth);					///< Scope for cloth simulation related items. Clothilde module
	MAXON_INTERNED_ID("net.maxon.asset.command.scope.pyro",					CommandScopePyro);					///< Scope for Pyro simmulation related items.
	MAXON_INTERNED_ID("net.maxon.asset.command.scope.bullet",				CommandScopeBullet);				///< Scope for Bullet simulation related items.
	MAXON_INTERNED_ID("net.maxon.asset.command.scope.camera",				CommandScopeCamera);				///< Scope for camera related items. Motioncam module.
	MAXON_INTERNED_ID("net.maxon.asset.command.scope.lighting",			CommandScopeLighting);			///< Scope for lights and lighting related items.
	MAXON_INTERNED_ID("net.maxon.asset.command.scope.animation",		CommandScopeAnimation);			///< Scope for keyframing and general animation items.
	MAXON_INTERNED_ID("net.maxon.asset.command.scope.powerslider",	CommandScopePowerslider);		///< Scope for the powerslider animation items. Time Scrollbar module.
	MAXON_INTERNED_ID("net.maxon.asset.command.scope.mograph",			CommandScopeMograph);				///< Scope for MoGraph related items.
	MAXON_INTERNED_ID("net.maxon.asset.command.scope.tracker",			CommandScopeTracker);				///< Scope for Tracking related items. Motiontracker & Motion Tracker Graph View Manager modules.
	MAXON_INTERNED_ID("net.maxon.asset.command.scope.viewport",			CommandScopeViewport);			///< Scope for Viewport related items.
	MAXON_INTERNED_ID("net.maxon.asset.command.scope.assetbrowser",	CommandScopeAssetBrowser);	///< Scope for Asset Browser related items.
	MAXON_INTERNED_ID("net.maxon.asset.command.scope.rendering",		CommandScopeRendering);			///< Scope for general Rendering and related items.
	MAXON_INTERNED_ID("net.maxon.asset.command.scope.teamrender",		CommandScopeTeamRender);		///< Scope for Team Render related items. Teamrender module
	MAXON_INTERNED_ID("net.maxon.asset.command.scope.redshift",			CommandScopeRedshift);			///< Scope for Redshift related items. Redshift und Redshift4c4d modules
	MAXON_INTERNED_ID("net.maxon.asset.command.scope.substance",		CommandScopeSubstance);			///< Scope for Substance related items. Substance module.
	MAXON_INTERNED_ID("net.maxon.asset.command.scope.objects",			CommandScopeObjects);				///< Scope for object related items.
	MAXON_INTERNED_ID("net.maxon.asset.command.scope.python",				CommandScopePython);				///< Scope for programming related items.
	MAXON_INTERNED_ID("net.maxon.asset.command.scope.other",				CommandScopeOther);					///< Scope for ramaining items.
};

namespace AssetTypes
{
	/// AssetTypes::Command allows to store commands within in a repository
	MAXON_DECLARATION(AssetType, Command, "net.maxon.assettype.command");
};

#include "asset_command1.hxx"
#include "asset_command2.hxx"

}

#endif // ASSET_COMMAND_H__
