import os
import sys
import platform


def GetPrebuildModuleName():
    s = platform.system()
    if s == "Darwin":
        return "prebuildevent_macos"
    elif s == "Windows":
        return "prebuildevent_win"
    elif s == "Linux":
        return "prebuildevent_linux"
    else:
        raise ValueError("{} is unsupported".format(s))


def main():
    dir, fn = os.path.split(__file__)
    path = os.path.abspath(os.path.join(dir, "..", "..", "..", "modules", "pythonvm.module", "project"))
    if not os.path.exists(path):
        return

    if path not in sys.path:
        sys.path.append(path)

    m = __import__(GetPrebuildModuleName())
    m.main()


if __name__ == "__main__":
    main()
