</$objtype/mkfile

TARG=egsh
OFILES=list.$O\
	main.$O
HFILES=shell.h
BIN=/usr/$user/bin/$objtype
MAN=/sys/man/1

</sys/src/cmd/mkone

# this makes it so you don't need egsh already in /sys/man/1/
$MAN/egsh: egsh.man
	cp egsh.man $MAN/egsh
