# Python compiled to run with valgrind for the talk called:
# range(n): A Deceptively Complex Program
# This Dockerfile is effectively an implementation of:
# http://svn.python.org/projects/python/trunk/Misc/README.valgrind
# It was inspired by the following post:
# http://stackoverflow.com/questions/20112989/how-to-use-valgrind-with-python
FROM ubuntu:16.04
RUN apt-get -y update
RUN apt-get -y install build-essential
RUN apt-get -y install valgrind

# To get source code annotation with callgrind, the /tmp directory is used:
# After you export your callgrind output, you can apt-get source pythohn2.7
# in /tmp and use kcachegrind to explore the source code.
WORKDIR /tmp
RUN apt-get -y build-dep python2.7
RUN apt-get source python2.7

WORKDIR python2.7-2.7.12
RUN sed -i '127,185s/###//' Misc/valgrind-python.supp
RUN sed -i ':a;N;$!ba;s/#define Py_USING_MEMORY_DEBUGGER\n \*\// *\/\n#define Py_USING_MEMORY_DEBUGGER/' Objects/obmalloc.c
# NOTE: --without-pymalloc is not included here. We're interested in the
# actual performance of Python, and not in finding memory leaks. See the
# following for more details:
# http://svn.python.org/projects/python/trunk/Misc/README.valgrind
RUN ./configure --prefix=`pwd` --with-pydebug --with-valgrind
RUN make

CMD ./python -c "print('hello valgrind')"
