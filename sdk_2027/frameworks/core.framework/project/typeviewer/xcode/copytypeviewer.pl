$lldbinit = $ENV{"HOME"} . "/.lldbinit-Xcode";
$remove = $ARGV[0];
$add = $ARGV[1];
$result = "";
if (open INPUT, $lldbinit)
{
	while (<INPUT>)
	{
		$result .= $_ if (!/command script import .*\/$remove/&& !/command script import \"$add\"/);
	}
	close INPUT;
}
$result = "# automatically created .lldbinit-Xcode\n" if (!$result);
$result .= "command script import \"$add\"\n";
open OUTPUT, ">", $lldbinit;
print OUTPUT $result;
close OUTPUT;
