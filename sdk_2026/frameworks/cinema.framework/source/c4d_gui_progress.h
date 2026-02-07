/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef __C4D_GUI_PROGRESS__
#define __C4D_GUI_PROGRESS__

#include "c4d_gui.h"
#include "c4d_thread.h"

namespace cinema
{

	//----------------------------------------------------------------------------------------
/// @markInternal
//----------------------------------------------------------------------------------------
class ProgressThread : public C4DThread
{
public:
	virtual void Main();
	virtual const Char* GetThreadName();

	Bool Start(ProgressDialog* pdlg);
	void End();

private:
	ProgressDialog* AcquireAndLock();
	void AcquireAndClearLock();
	void MarkAsInClose(ProgressDialog* pdlg);
	void ReleaseLock(ProgressDialog* pdlg);

private:
	// keeps the memory layout compatible.
	maxon::AtomicPtr<ProgressDialog> dlg;
};

//----------------------------------------------------------------------------------------
/// This class is especially designed for progress dialogs.\n
/// Here is an implementation:
/// @code
/// class MyProgressDialog : public ProgressDialog
/// {
/// public:
/// 	virtual Bool CreateLayout();
/// 	virtual Bool InitValues();
///
/// 	virtual void Main(C4DThread *bt);
/// 	virtual String GetTitle() { return String("Progress"); }
/// };
///
/// Bool MyProgressDialog::CreateLayout()
/// {
/// 	return ProgressDialog::CreateLayout();
/// }
///
/// Bool MyProgressDialog::InitValues()
/// {
/// 	return ProgressDialog::InitValues();
/// }
///
/// void MyProgressDialog::Main(C4DThread *bt)
/// {
/// 	Int64 cnt = 100000000;
///
/// 	SetPercent(0.f);
///
/// 	for (Int64 i=0; i<cnt; i++)
/// 	{
/// 		SetPercent((Float)i/cnt);
/// 	}
///
/// 	SetPercent(1.f);
/// }
///
/// // Calling code
///
/// MyProgressDialog dlg;
/// return dlg.Open();
/// @endcode
//----------------------------------------------------------------------------------------
class ProgressDialog : public GeModalDialog
{
private:
	ProgressThread thread;
	Float percent;
	maxon::Spinlock deprecatedCallback_lock;
	void* (*deprectatedCallback)(void* context) = nullptr;
	void* deprectatedCallback_context = nullptr;
	void* deprectatedCallback_result = nullptr;

public:
	/// @name Modal Dialog
	/// @{

	//----------------------------------------------------------------------------------------
	/// Called when the dialog is about to be displayed. Override this method to define the layout of the dialog.\n
	/// Either use the recommended @ref LoadDialogResource function or the manual functions (for example AddButton()).
	/// See @link page_dialog_layout Dialog Layout@endlink for more information.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	virtual Bool CreateLayout();

	//----------------------------------------------------------------------------------------
	/// Called when the dialog is initialized by the GUI. Override this method to initialize local variables and the gadgets used.
	/// @see The article @link page_gui_messages GUI Messages@endlink for more information.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	virtual Bool InitValues();

	//----------------------------------------------------------------------------------------
	/// Called when a timer event is received.\n
	/// To subscribe to timer events use SetTimer().
	/// @param[in] msg								The timer message container.
	//----------------------------------------------------------------------------------------
	virtual void Timer(const BaseContainer& msg);

	//----------------------------------------------------------------------------------------
	/// Called when a message is received.\n
	/// Override this function to react to special messages.\n
	/// Normally this is not necessary. Be sure to include a call the parent version of this function, ProgressDialog::Message(msg, result).
	/// @see The article @link page_gui_messages GUI Messages@endlink for more information.
	/// @param[in] msg								The message container.
	/// @param[in] result							A container to place results in.
	/// @return												Depends on the message.
	//----------------------------------------------------------------------------------------
	virtual Int32 Message(const BaseContainer& msg, BaseContainer& result);

	//----------------------------------------------------------------------------------------
	/// Whenever the user clicks on a gadget and/or changes its value this function will be called. It is also called when a string menu item is selected. Override this methods to handle such events.
	/// @note Remember StopAllThreads() must be called before making modifications to the scene.
	/// @param[in] id									The ID of the gadget that triggered the event.
	/// @param[in] msg								The message container. Contains the following values: @ref BFM_ACTION_ID and @ref BFM_ACTION_VALUE.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	virtual Bool Command(Int32 id, const BaseContainer& msg);

	//----------------------------------------------------------------------------------------
	/// If the user wants to close the dialog with the OK button this function will be called. Override it to avoid closing the dialog if an error situation has occurred.\n
	/// If @formatConstant{false} is returned everything will be as usual, but if @formatConstant{true} is returned the dialog will not close.
	/// @warning A buggy function, always returning @formatConstant{true}, will lead to a frustrating user experience.
	/// @return												@formatConstant{true} if the dialog should not be closed, @formatConstant{false} if it should.
	//----------------------------------------------------------------------------------------
	virtual Bool AskClose();

	/// @}

	/// @name Miscellaneous
	/// @{

	//----------------------------------------------------------------------------------------
	/// Sets the progress bar.
	/// @param[in] p									The percentage for the progress bar. Goes from @em 0.0 to @em 1.0 (@em 0-@em 100%).
	//----------------------------------------------------------------------------------------
	void SetPercent(Float p);

	//----------------------------------------------------------------------------------------
	/// Gets the calling thread for the dialog.
	/// @return												The calling thread.
	//----------------------------------------------------------------------------------------
	C4DThread* GetThread();

	/// @}

	/// @name Override
	/// @{

	//----------------------------------------------------------------------------------------
	/// Called to execute code within the progress thread.
	/// @param[in] bt									The progress thread.
	//----------------------------------------------------------------------------------------
	virtual void Main(C4DThread* bt) = 0;

	//----------------------------------------------------------------------------------------
	/// Called to retrieve the title of the progress dialog.
	/// @return												The title.
	//----------------------------------------------------------------------------------------
	virtual String GetTitle() = 0;

	/// @}
};

} // namespace cinema


#endif // __C4D_GUI_PROGRESS__
