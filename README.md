INI2JSON
========

Converts INI files to valid JSON
--------------------------------

### About

This program was written and tested in about six man-hours (I wasn't
fully focused, admittedly, so with all the stops included, it was closer
to nine).  Its sole purpose is to read in an INI file and turn it into
valid JSON.  It can either read the stream or a file.  It is pipe-aware
and outputs to the standard console stream (see section `USAGE` for more
details).

### Why INI to JSON?

The popular 2D game, [Terraria][terraria], has a very active modding
community.  So when I heard that the makers of [tConfig][tconfig] were
scrapping their old code in favor of something more [modern][tAPI], I
was thrilled that they were going to be using JSON instead of the (very
dated, yet still reliable enough, for some) INI file format.

However, someone in the community complained, and I felt compelled to
make this little program to show them just how easily an INI file *can*
be converted, and with the hope that they'll use it as a starting place
only, as the best JSON is the hand-checked, machine-validated JSON, in
my opinion.

### How to Build

`ini2json` only relies on ANSI standard libraries.  As a result, on my
*particular* Mac, I got it to build with [`g++`][gcc] and
[`clang++`][clang] without errors.  It should be as cross-compatible as
possible, not even forcing `using namespace std;` on your code, should
you choose to take the parser to use in your own stuff.

So, on to building:

`clang++ ini2json.cpp -o ini2json`

or g++, or hopefully *ANY* C++ compiler.  Uses Linux endings, tested on
a Mac OS X 10.6.8.

### USAGE

Once the program is built, it's easy to use the program in a variety of
ways.  Using the supplied example `test.ini`:

`cat test.ini | ./ini2json > test.json`

`./ini2json test.ini > test.json`

Or, to enter it manually, just run `ini2json` with no parameters.

### Installing

To install in a UNIX environment, you can install via `/usr/bin/install
-C ./ini2json /usr/local/bin`, assuming that folder is in your `$PATH`.

On Windows, check your `%PATH%` variable for a good place to install it,
or, if in a Cygwin/MinGW environment, see the above statement for UNIX.

[clang]:    https://clang.llvm.org/
[gcc]:      https://gcc.gnu.org/
[terraria]: https://www.terrariaonline.com/
[tconfig]:  https://www.terrariaonline.com/threads/discontinued-tconfig-a-mod-to-make-mods.52207/
[tAPI]:     https://www.terrariaonline.com/threads/tapi-general-discussion-progress-info.110832/
