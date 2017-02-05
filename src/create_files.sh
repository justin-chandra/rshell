#!/bin/sh
echo "#include <iostream>" >> $1.h
echo "" >> $1.h
echo "using namespace std;" >> $1.h

echo "" >> $1.h
echo "#ifndef $1_H" >> $1.h
echo "#define $1_H" >> $1.h

echo "" >> $1.h
echo "class $1" >> $1.h
echo "{" >> $1.h
echo "	public:" >> $1.h
echo "	$1();" >> $1.h
echo "	~$1();" >> $1.h
echo "" >> $1.h
echo "	private:" >> $1.h
echo "};" >> $1.h

echo "" >> $1.h
echo "#endif" >> $1.h

echo  "#include <iostream>" >> $1.cpp
echo "" >> $1.cpp
echo "using namespace std;" >> $1.cpp
echo "" >> $1.cpp

echo  "#include \"$1.h\"" >> $1.cpp


echo "" >> $1.cpp
echo "$1::$1()" >> $1.cpp
echo "{" >> $1.cpp
echo "" >> $1.cpp
echo "}" >> $1.cpp

echo "" >> $1.cpp
echo "$1::~$1()" >> $1.cpp
echo "{" >> $1.cpp
echo "" >> $1.cpp
echo "}" >> $1.cpp
