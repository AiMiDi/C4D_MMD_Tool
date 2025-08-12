REM -- Create target directory
if not exist %1 (
  md %1
)

REM -- Check for target directory, possibly skip copy calls
if not exist %1 (
  goto ERRORDIR
)

REM -- Copy natvis and natstepfilter files
copy %2\*.* %1 > NUL
goto ENDOFTHESTORY

REM -- Directory error
:ERRORDIR
goto ENDOFTHESTORY

:ENDOFTHESTORY
