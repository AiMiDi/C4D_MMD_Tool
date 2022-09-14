#
# Test script for the curses module
#
# This script doesn't actually display anything very coherent. but it
# does call (nearly) every method and function.
#
# Functions not tested: {def,reset}_{shell,prog}_mode, getch(), getstr()
# Only called, not tested: getmouse(), ungetmouse()
#

import os
import string
import sys
import tempfile
import functools
import unittest

from test.support import requires, import_module, verbose, SaveSignals

# Optionally test curses module.  This currently requires that the
# 'curses' resource be given on the regrtest command line using the -u
# option.  If not available, nothing after this line will be executed.
import inspect
requires('curses')

# If either of these don't exist, skip the tests.
curses = import_module('curses')
import_module('curses.ascii')
import_module('curses.textpad')
try:
    import curses.panel
except ImportError:
    pass

def requires_curses_func(name):
    return unittest.skipUnless(hasattr(curses, name),
                               'requires curses.%s' % name)

def requires_colors(test):
    @functools.wraps(test)
    def wrapped(self, *args, **kwargs):
        if not curses.has_colors():
            self.skipTest('requires colors support')
        curses.start_color()
        test(self, *args, **kwargs)
    return wrapped

term = os.environ.get('TERM')
SHORT_MAX = 0x7fff

# If newterm was supported we could use it instead of initscr and not exit
@unittest.skipIf(not term or term == 'unknown',
                 "$TERM=%r, calling initscr() may cause exit" % term)
@unittest.skipIf(sys.platform == "cygwin",
                 "cygwin's curses mostly just hangs")
class TestCurses(unittest.TestCase):

    @classmethod
    def setUpClass(cls):
        if verbose:
            print(f'TERM={term}', file=sys.stderr, flush=True)
        # testing setupterm() inside initscr/endwin
        # causes terminal breakage
        stdout_fd = sys.__stdout__.fileno()
        curses.setupterm(fd=stdout_fd)

    def setUp(self):
        self.isatty = True
        self.output = sys.__stdout__
        stdout_fd = sys.__stdout__.fileno()
        if not sys.__stdout__.isatty():
            # initstr() unconditionally uses C stdout.
            # If it is redirected to file or pipe, try to attach it
            # to terminal.
            # First, save a copy of the file descriptor of stdout, so it
            # can be restored after finishing the test.
            dup_fd = os.dup(stdout_fd)
            self.addCleanup(os.close, dup_fd)
            self.addCleanup(os.dup2, dup_fd, stdout_fd)

            if sys.__stderr__.isatty():
                # If stderr is connected to terminal, use it.
                tmp = sys.__stderr__
                self.output = sys.__stderr__
            else:
                try:
                    # Try to open the terminal device.
                    tmp = open('/dev/tty', 'wb', buffering=0)
                except OSError:
                    # As a fallback, use regular file to write control codes.
                    # Some functions (like savetty) will not work, but at
                    # least the garbage control sequences will not be mixed
                    # with the testing report.
                    tmp = tempfile.TemporaryFile(mode='wb', buffering=0)
                    self.isatty = False
                self.addCleanup(tmp.close)
                self.output = None
            os.dup2(tmp.fileno(), stdout_fd)

        self.save_signals = SaveSignals()
        self.save_signals.save()
        self.addCleanup(self.save_signals.restore)
        if verbose and self.output is not None:
            # just to make the test output a little more readable
            sys.stderr.flush()
            sys.stdout.flush()
            print(file=self.output, flush=True)
        self.stdscr = curses.initscr()
        if self.isatty:
            curses.savetty()
            self.addCleanup(curses.endwin)
            self.addCleanup(curses.resetty)

    def test_window_funcs(self):
        "Test the methods of windows"
        stdscr = self.stdscr
        win = curses.newwin(10,10)
        win = curses.newwin(5,5, 5,5)
        win2 = curses.newwin(15,15, 5,5)

        for meth in [stdscr.addch, stdscr.addstr]:
            for args in [('a',), ('a', curses.A_BOLD),
                         (4,4, 'a'), (5,5, 'a', curses.A_BOLD)]:
                with self.subTest(meth=meth.__qualname__, args=args):
                    meth(*args)

        for meth in [stdscr.clear, stdscr.clrtobot,
                     stdscr.clrtoeol, stdscr.cursyncup, stdscr.delch,
                     stdscr.deleteln, stdscr.erase, stdscr.getbegyx,
                     stdscr.getbkgd, stdscr.getmaxyx,
                     stdscr.getparyx, stdscr.getyx, stdscr.inch,
                     stdscr.insertln, stdscr.instr, stdscr.is_wintouched,
                     win.noutrefresh, stdscr.redrawwin, stdscr.refresh,
                     stdscr.standout, stdscr.standend, stdscr.syncdown,
                     stdscr.syncup, stdscr.touchwin, stdscr.untouchwin]:
            with self.subTest(meth=meth.__qualname__):
                meth()

        stdscr.addnstr('1234', 3)
        stdscr.addnstr('1234', 3, curses.A_BOLD)
        stdscr.addnstr(4,4, '1234', 3)
        stdscr.addnstr(5,5, '1234', 3, curses.A_BOLD)

        stdscr.attron(curses.A_BOLD)
        stdscr.attroff(curses.A_BOLD)
        stdscr.attrset(curses.A_BOLD)
        stdscr.bkgd(' ')
        stdscr.bkgd(' ', curses.A_REVERSE)
        stdscr.bkgdset(' ')
        stdscr.bkgdset(' ', curses.A_REVERSE)

        win.border(65, 66, 67, 68,
                   69, 70, 71, 72)
        win.border('|', '!', '-', '_',
                   '+', '\\', '#', '/')
        with self.assertRaises(TypeError,
                               msg="Expected win.border() to raise TypeError"):
            win.border(65, 66, 67, 68,
                       69, [], 71, 72)

        win.box(65, 67)
        win.box('!', '_')
        win.box(b':', b'~')
        self.assertRaises(TypeError, win.box, 65, 66, 67)
        self.assertRaises(TypeError, win.box, 65)
        win.box()

        stdscr.clearok(1)

        win4 = stdscr.derwin(2,2)
        win4 = stdscr.derwin(1,1, 5,5)
        win4.mvderwin(9,9)

        stdscr.echochar('a')
        stdscr.echochar('a', curses.A_BOLD)
        stdscr.hline('-', 5)
        stdscr.hline('-', 5, curses.A_BOLD)
        stdscr.hline(1,1,'-', 5)
        stdscr.hline(1,1,'-', 5, curses.A_BOLD)

        stdscr.idcok(1)
        stdscr.idlok(1)
        if hasattr(stdscr, 'immedok'):
            stdscr.immedok(1)
            stdscr.immedok(0)
        stdscr.insch('c')
        stdscr.insdelln(1)
        stdscr.insnstr('abc', 3)
        stdscr.insnstr('abc', 3, curses.A_BOLD)
        stdscr.insnstr(5, 5, 'abc', 3)
        stdscr.insnstr(5, 5, 'abc', 3, curses.A_BOLD)

        stdscr.insstr('def')
        stdscr.insstr('def', curses.A_BOLD)
        stdscr.insstr(5, 5, 'def')
        stdscr.insstr(5, 5, 'def', curses.A_BOLD)
        stdscr.is_linetouched(0)
        stdscr.keypad(1)
        stdscr.leaveok(1)
        stdscr.move(3,3)
        win.mvwin(2,2)
        stdscr.nodelay(1)
        stdscr.notimeout(1)
        win2.overlay(win)
        win2.overwrite(win)
        win2.overlay(win, 1, 2, 2, 1, 3, 3)
        win2.overwrite(win, 1, 2, 2, 1, 3, 3)
        stdscr.redrawln(1,2)

        stdscr.scrollok(1)
        stdscr.scroll()
        stdscr.scroll(2)
        stdscr.scroll(-3)

        stdscr.move(12, 2)
        stdscr.setscrreg(10,15)
        win3 = stdscr.subwin(10,10)
        win3 = stdscr.subwin(10,10, 5,5)
        if hasattr(stdscr, 'syncok') and not sys.platform.startswith("sunos"):
            stdscr.syncok(1)
        stdscr.timeout(5)
        stdscr.touchline(5,5)
        stdscr.touchline(5,5,0)
        stdscr.vline('a', 3)
        stdscr.vline('a', 3, curses.A_STANDOUT)
        if hasattr(stdscr, 'chgat'):
            stdscr.chgat(5, 2, 3, curses.A_BLINK)
            stdscr.chgat(3, curses.A_BOLD)
            stdscr.chgat(5, 8, curses.A_UNDERLINE)
            stdscr.chgat(curses.A_BLINK)
        stdscr.refresh()

        stdscr.vline(1,1, 'a', 3)
        stdscr.vline(1,1, 'a', 3, curses.A_STANDOUT)

        if hasattr(stdscr, 'resize'):
            stdscr.resize(25, 80)
        if hasattr(stdscr, 'enclose'):
            stdscr.enclose(10, 10)

        with tempfile.TemporaryFile() as f:
            self.stdscr.putwin(f)
            f.seek(0)
            curses.getwin(f)

        self.assertRaises(ValueError, stdscr.getstr, -400)
        self.assertRaises(ValueError, stdscr.getstr, 2, 3, -400)
        self.assertRaises(ValueError, stdscr.instr, -2)
        self.assertRaises(ValueError, stdscr.instr, 2, 3, -2)

    def test_embedded_null_chars(self):
        # reject embedded null bytes and characters
        stdscr = self.stdscr
        for arg in ['a', b'a']:
            with self.subTest(arg=arg):
                self.assertRaises(ValueError, stdscr.addstr, 'a\0')
                self.assertRaises(ValueError, stdscr.addnstr, 'a\0', 1)
                self.assertRaises(ValueError, stdscr.insstr, 'a\0')
                self.assertRaises(ValueError, stdscr.insnstr, 'a\0', 1)

    def test_module_funcs(self):
        "Test module-level functions"
        for func in [curses.baudrate, curses.beep, curses.can_change_color,
                     curses.doupdate, curses.flash, curses.flushinp,
                     curses.has_colors, curses.has_ic, curses.has_il,
                     curses.isendwin, curses.killchar, curses.longname,
                     curses.noecho, curses.nonl, curses.noqiflush,
                     curses.termattrs, curses.termname, curses.erasechar]:
            with self.subTest(func=func.__qualname__):
                func()
        if self.isatty:
            for func in [curses.cbreak, curses.def_prog_mode,
                         curses.nocbreak, curses.noraw,
                         curses.reset_prog_mode]:
                with self.subTest(func=func.__qualname__):
                    func()
        if hasattr(curses, 'filter'):
            curses.filter()
        if hasattr(curses, 'getsyx'):
            curses.getsyx()

        # Functions that actually need arguments
        if curses.tigetstr("cnorm"):
            curses.curs_set(1)
        curses.delay_output(1)
        curses.echo() ; curses.echo(1)

        curses.halfdelay(1)
        if self.isatty:
            curses.intrflush(1)
        curses.meta(1)
        curses.napms(100)
        curses.newpad(50,50)
        win = curses.newwin(5,5)
        win = curses.newwin(5,5, 1,1)
        curses.nl() ; curses.nl(1)
        curses.putp(b'abc')
        curses.qiflush()
        if self.isatty:
            curses.raw() ; curses.raw(1)
        curses.set_escdelay(25)
        self.assertEqual(curses.get_escdelay(), 25)
        curses.set_tabsize(4)
        self.assertEqual(curses.get_tabsize(), 4)
        if hasattr(curses, 'setsyx'):
            curses.setsyx(5,5)
        curses.tigetflag('hc')
        curses.tigetnum('co')
        curses.tigetstr('cr')
        curses.tparm(b'cr')
        if hasattr(curses, 'typeahead'):
            curses.typeahead(sys.__stdin__.fileno())
        curses.unctrl('a')
        curses.ungetch('a')
        if hasattr(curses, 'use_env'):
            curses.use_env(1)

    # Functions only available on a few platforms

    def bad_colors(self):
        return (-2**31 - 1, 2**31, -2**63 - 1, 2**63, 2**64)

    def bad_pairs(self):
        return (-2**31 - 1, 2**31, -2**63 - 1, 2**63, 2**64)

    def test_start_color(self):
        if not curses.has_colors():
            self.skipTest('requires colors support')
        curses.start_color()
        if verbose:
            print(f'COLORS = {curses.COLORS}', file=sys.stderr)
            print(f'COLOR_PAIRS = {curses.COLOR_PAIRS}', file=sys.stderr)

    @requires_colors
    def test_color_content(self):
        self.assertEqual(curses.color_content(curses.COLOR_BLACK), (0, 0, 0))
        curses.color_content(0)
        maxcolor = min(curses.COLORS - 1, SHORT_MAX)
        curses.color_content(maxcolor)

        for color in self.bad_colors():
            self.assertRaises(OverflowError, curses.color_content, color)
        if curses.COLORS <= SHORT_MAX:
            self.assertRaises(curses.error, curses.color_content, curses.COLORS)
        self.assertRaises(curses.error, curses.color_content, -1)

    @requires_colors
    def test_init_color(self):
        if not curses.can_change_color:
            self.skipTest('cannot change color')

        old = curses.color_content(0)
        try:
            curses.init_color(0, *old)
        except curses.error:
            self.skipTest('cannot change color (init_color() failed)')
        self.addCleanup(curses.init_color, 0, *old)
        curses.init_color(0, 0, 0, 0)
        self.assertEqual(curses.color_content(0), (0, 0, 0))
        curses.init_color(0, 1000, 1000, 1000)
        self.assertEqual(curses.color_content(0), (1000, 1000, 1000))

        maxcolor = min(curses.COLORS - 1, SHORT_MAX)
        old = curses.color_content(maxcolor)
        curses.init_color(maxcolor, *old)
        self.addCleanup(curses.init_color, maxcolor, *old)
        curses.init_color(maxcolor, 0, 500, 1000)
        self.assertEqual(curses.color_content(maxcolor), (0, 500, 1000))

        for color in self.bad_colors():
            self.assertRaises(OverflowError, curses.init_color, color, 0, 0, 0)
        if curses.COLORS <= SHORT_MAX:
            self.assertRaises(curses.error, curses.init_color, curses.COLORS, 0, 0, 0)
        self.assertRaises(curses.error, curses.init_color, -1, 0, 0, 0)
        for comp in (-1, 1001):
            self.assertRaises(curses.error, curses.init_color, 0, comp, 0, 0)
            self.assertRaises(curses.error, curses.init_color, 0, 0, comp, 0)
            self.assertRaises(curses.error, curses.init_color, 0, 0, 0, comp)

    def get_pair_limit(self):
        return min(curses.COLOR_PAIRS, SHORT_MAX)

    @requires_colors
    def test_pair_content(self):
        if not hasattr(curses, 'use_default_colors'):
            self.assertEqual(curses.pair_content(0),
                             (curses.COLOR_WHITE, curses.COLOR_BLACK))
        curses.pair_content(0)
        maxpair = self.get_pair_limit() - 1
        if maxpair > 0:
            curses.pair_content(maxpair)

        for pair in self.bad_pairs():
            self.assertRaises(OverflowError, curses.pair_content, pair)
        self.assertRaises(curses.error, curses.pair_content, -1)

    @requires_colors
    def test_init_pair(self):
        old = curses.pair_content(1)
        curses.init_pair(1, *old)
        self.addCleanup(curses.init_pair, 1, *old)

        curses.init_pair(1, 0, 0)
        self.assertEqual(curses.pair_content(1), (0, 0))
        maxcolor = min(curses.COLORS - 1, SHORT_MAX)
        curses.init_pair(1, maxcolor, 0)
        self.assertEqual(curses.pair_content(1), (maxcolor, 0))
        curses.init_pair(1, 0, maxcolor)
        self.assertEqual(curses.pair_content(1), (0, maxcolor))
        maxpair = self.get_pair_limit() - 1
        if maxpair > 1:
            curses.init_pair(maxpair, 0, 0)
            self.assertEqual(curses.pair_content(maxpair), (0, 0))

        for pair in self.bad_pairs():
            self.assertRaises(OverflowError, curses.init_pair, pair, 0, 0)
        self.assertRaises(curses.error, curses.init_pair, -1, 0, 0)
        for color in self.bad_colors():
            self.assertRaises(OverflowError, curses.init_pair, 1, color, 0)
            self.assertRaises(OverflowError, curses.init_pair, 1, 0, color)
        if curses.COLORS <= SHORT_MAX:
            self.assertRaises(curses.error, curses.init_pair, 1, curses.COLORS, 0)
            self.assertRaises(curses.error, curses.init_pair, 1, 0, curses.COLORS)

    @requires_colors
    def test_color_attrs(self):
        for pair in 0, 1, 255:
            attr = curses.color_pair(pair)
            self.assertEqual(curses.pair_number(attr), pair, attr)
            self.assertEqual(curses.pair_number(attr | curses.A_BOLD), pair)
        self.assertEqual(curses.color_pair(0), 0)
        self.assertEqual(curses.pair_number(0), 0)

    @requires_curses_func('use_default_colors')
    @requires_colors
    def test_use_default_colors(self):
        self.assertIn(curses.pair_content(0),
                      ((curses.COLOR_WHITE, curses.COLOR_BLACK), (-1, -1)))
        curses.use_default_colors()
        self.assertEqual(curses.pair_content(0), (-1, -1))

    @requires_curses_func('keyname')
    def test_keyname(self):
        curses.keyname(13)

    @requires_curses_func('has_key')
    def test_has_key(self):
        curses.has_key(13)

    @requires_curses_func('getmouse')
    def test_getmouse(self):
        (availmask, oldmask) = curses.mousemask(curses.BUTTON1_PRESSED)
        if availmask == 0:
            self.skipTest('mouse stuff not available')
        curses.mouseinterval(10)
        # just verify these don't cause errors
        curses.ungetmouse(0, 0, 0, 0, curses.BUTTON1_PRESSED)
        m = curses.getmouse()

    @requires_curses_func('panel')
    def test_userptr_without_set(self):
        w = curses.newwin(10, 10)
        p = curses.panel.new_panel(w)
        # try to access userptr() before calling set_userptr() -- segfaults
        with self.assertRaises(curses.panel.error,
                               msg='userptr should fail since not set'):
            p.userptr()

    @requires_curses_func('panel')
    def test_userptr_memory_leak(self):
        w = curses.newwin(10, 10)
        p = curses.panel.new_panel(w)
        obj = object()
        nrefs = sys.getrefcount(obj)
        for i in range(100):
            p.set_userptr(obj)

        p.set_userptr(None)
        self.assertEqual(sys.getrefcount(obj), nrefs,
                         "set_userptr leaked references")

    @requires_curses_func('panel')
    def test_userptr_segfault(self):
        w = curses.newwin(10, 10)
        panel = curses.panel.new_panel(w)
        class A:
            def __del__(self):
                panel.set_userptr(None)
        panel.set_userptr(A())
        panel.set_userptr(None)

    @requires_curses_func('panel')
    def test_new_curses_panel(self):
        w = curses.newwin(10, 10)
        panel = curses.panel.new_panel(w)
        self.assertRaises(TypeError, type(panel))

    @requires_curses_func('is_term_resized')
    def test_is_term_resized(self):
        curses.is_term_resized(*self.stdscr.getmaxyx())

    @requires_curses_func('resize_term')
    def test_resize_term(self):
        curses.resize_term(*self.stdscr.getmaxyx())

    @requires_curses_func('resizeterm')
    def test_resizeterm(self):
        lines, cols = curses.LINES, curses.COLS
        new_lines = lines - 1
        new_cols = cols + 1
        curses.resizeterm(new_lines, new_cols)

        self.assertEqual(curses.LINES, new_lines)
        self.assertEqual(curses.COLS, new_cols)

    def test_issue6243(self):
        curses.ungetch(1025)
        self.stdscr.getkey()

    @requires_curses_func('unget_wch')
    @unittest.skipIf(getattr(curses, 'ncurses_version', (99,)) < (5, 8),
                     "unget_wch is broken in ncurses 5.7 and earlier")
    def test_unget_wch(self):
        stdscr = self.stdscr
        encoding = stdscr.encoding
        for ch in ('a', '\xe9', '\u20ac', '\U0010FFFF'):
            try:
                ch.encode(encoding)
            except UnicodeEncodeError:
                continue
            try:
                curses.unget_wch(ch)
            except Exception as err:
                self.fail("unget_wch(%a) failed with encoding %s: %s"
                          % (ch, stdscr.encoding, err))
            read = stdscr.get_wch()
            self.assertEqual(read, ch)

            code = ord(ch)
            curses.unget_wch(code)
            read = stdscr.get_wch()
            self.assertEqual(read, ch)

    def test_issue10570(self):
        b = curses.tparm(curses.tigetstr("cup"), 5, 3)
        self.assertIs(type(b), bytes)

    def test_encoding(self):
        stdscr = self.stdscr
        import codecs
        encoding = stdscr.encoding
        codecs.lookup(encoding)
        with self.assertRaises(TypeError):
            stdscr.encoding = 10
        stdscr.encoding = encoding
        with self.assertRaises(TypeError):
            del stdscr.encoding

    def test_issue21088(self):
        stdscr = self.stdscr
        #
        # http://bugs.python.org/issue21088
        #
        # the bug:
        # when converting curses.window.addch to Argument Clinic
        # the first two parameters were switched.

        # if someday we can represent the signature of addch
        # we will need to rewrite this test.
        try:
            signature = inspect.signature(stdscr.addch)
            self.assertFalse(signature)
        except ValueError:
            # not generating a signature is fine.
            pass

        # So.  No signature for addch.
        # But Argument Clinic gave us a human-readable equivalent
        # as the first line of the docstring.  So we parse that,
        # and ensure that the parameters appear in the correct order.
        # Since this is parsing output from Argument Clinic, we can
        # be reasonably certain the generated parsing code will be
        # correct too.
        human_readable_signature = stdscr.addch.__doc__.split("\n")[0]
        self.assertIn("[y, x,]", human_readable_signature)

    def test_issue13051(self):
        stdscr = self.stdscr
        if not hasattr(stdscr, 'resize'):
            raise unittest.SkipTest('requires curses.window.resize')
        box = curses.textpad.Textbox(stdscr, insert_mode=True)
        lines, cols = stdscr.getmaxyx()
        stdscr.resize(lines-2, cols-2)
        # this may cause infinite recursion, leading to a RuntimeError
        box._insert_printable_char('a')


class MiscTests(unittest.TestCase):

    @requires_curses_func('update_lines_cols')
    def test_update_lines_cols(self):
        # this doesn't actually test that LINES and COLS are updated,
        # because we can't automate changing them. See Issue #4254 for
        # a manual test script. We can only test that the function
        # can be called.
        curses.update_lines_cols()

    @requires_curses_func('ncurses_version')
    def test_ncurses_version(self):
        v = curses.ncurses_version
        if verbose:
            print(f'ncurses_version = {curses.ncurses_version}', flush=True)
        self.assertIsInstance(v[:], tuple)
        self.assertEqual(len(v), 3)
        self.assertIsInstance(v[0], int)
        self.assertIsInstance(v[1], int)
        self.assertIsInstance(v[2], int)
        self.assertIsInstance(v.major, int)
        self.assertIsInstance(v.minor, int)
        self.assertIsInstance(v.patch, int)
        self.assertEqual(v[0], v.major)
        self.assertEqual(v[1], v.minor)
        self.assertEqual(v[2], v.patch)
        self.assertGreaterEqual(v.major, 0)
        self.assertGreaterEqual(v.minor, 0)
        self.assertGreaterEqual(v.patch, 0)

class TestAscii(unittest.TestCase):

    def test_controlnames(self):
        for name in curses.ascii.controlnames:
            self.assertTrue(hasattr(curses.ascii, name), name)

    def test_ctypes(self):
        def check(func, expected):
            with self.subTest(ch=c, func=func):
                self.assertEqual(func(i), expected)
                self.assertEqual(func(c), expected)

        for i in range(256):
            c = chr(i)
            b = bytes([i])
            check(curses.ascii.isalnum, b.isalnum())
            check(curses.ascii.isalpha, b.isalpha())
            check(curses.ascii.isdigit, b.isdigit())
            check(curses.ascii.islower, b.islower())
            check(curses.ascii.isspace, b.isspace())
            check(curses.ascii.isupper, b.isupper())

            check(curses.ascii.isascii, i < 128)
            check(curses.ascii.ismeta, i >= 128)
            check(curses.ascii.isctrl, i < 32)
            check(curses.ascii.iscntrl, i < 32 or i == 127)
            check(curses.ascii.isblank, c in ' \t')
            check(curses.ascii.isgraph, 32 < i <= 126)
            check(curses.ascii.isprint, 32 <= i <= 126)
            check(curses.ascii.ispunct, c in string.punctuation)
            check(curses.ascii.isxdigit, c in string.hexdigits)

        for i in (-2, -1, 256, sys.maxunicode, sys.maxunicode+1):
            self.assertFalse(curses.ascii.isalnum(i))
            self.assertFalse(curses.ascii.isalpha(i))
            self.assertFalse(curses.ascii.isdigit(i))
            self.assertFalse(curses.ascii.islower(i))
            self.assertFalse(curses.ascii.isspace(i))
            self.assertFalse(curses.ascii.isupper(i))

            self.assertFalse(curses.ascii.isascii(i))
            self.assertFalse(curses.ascii.isctrl(i))
            self.assertFalse(curses.ascii.iscntrl(i))
            self.assertFalse(curses.ascii.isblank(i))
            self.assertFalse(curses.ascii.isgraph(i))
            self.assertFalse(curses.ascii.isprint(i))
            self.assertFalse(curses.ascii.ispunct(i))
            self.assertFalse(curses.ascii.isxdigit(i))

        self.assertFalse(curses.ascii.ismeta(-1))

    def test_ascii(self):
        ascii = curses.ascii.ascii
        self.assertEqual(ascii('\xc1'), 'A')
        self.assertEqual(ascii('A'), 'A')
        self.assertEqual(ascii(ord('\xc1')), ord('A'))

    def test_ctrl(self):
        ctrl = curses.ascii.ctrl
        self.assertEqual(ctrl('J'), '\n')
        self.assertEqual(ctrl('\n'), '\n')
        self.assertEqual(ctrl('@'), '\0')
        self.assertEqual(ctrl(ord('J')), ord('\n'))

    def test_alt(self):
        alt = curses.ascii.alt
        self.assertEqual(alt('\n'), '\x8a')
        self.assertEqual(alt('A'), '\xc1')
        self.assertEqual(alt(ord('A')), 0xc1)

    def test_unctrl(self):
        unctrl = curses.ascii.unctrl
        self.assertEqual(unctrl('a'), 'a')
        self.assertEqual(unctrl('A'), 'A')
        self.assertEqual(unctrl(';'), ';')
        self.assertEqual(unctrl(' '), ' ')
        self.assertEqual(unctrl('\x7f'), '^?')
        self.assertEqual(unctrl('\n'), '^J')
        self.assertEqual(unctrl('\0'), '^@')
        self.assertEqual(unctrl(ord('A')), 'A')
        self.assertEqual(unctrl(ord('\n')), '^J')
        # Meta-bit characters
        self.assertEqual(unctrl('\x8a'), '!^J')
        self.assertEqual(unctrl('\xc1'), '!A')
        self.assertEqual(unctrl(ord('\x8a')), '!^J')
        self.assertEqual(unctrl(ord('\xc1')), '!A')


if __name__ == '__main__':
    unittest.main()
