#!/bin/bash

function Create
{
 local Name=$1
 if [[ "$Name" == "" ]]; then
  Name=Doxyfile
 fi
# echo "Create( )                                                                              " 1>&2
# echo " Name:                                    \"$Name\"                                    " 1>&2
 doxygen $Name
}

function Generate
{
 local Name=$1
 if [[ "$Name" == "" ]]; then
  Name=Doxyfile
 fi
# echo "Generate( )                                                                            " 1>&2
# echo " Name:                                    \"$Name\"                                    " 1>&2
 doxygen -g $Name
}

function Usage
{
 echo "USAGE:"
 echo " $0 -?"
 echo " $0 --help"
 echo "       print this text"
 echo ""
 echo " $0 c           [ <DoxyFileName> ]"
 echo " $0 create      [ <DoxyFileName> ]"
 echo "       creates the documentation using the doxyfile with name \"<DoxyFileName>\""
 echo "       if optional parameter <DoxyFileName>  is not given, the name of \"Doxyfile\" will be used"
 echo ""
 echo " $0 g           [ <DoxyFileName> ]"
 echo " $0 generate    [ <DoxyFileName> ]"
 echo "       generate a new doxyfile with name \"<DoxyFileName>\""
 echo "       if optional parameter <DoxyFileName>  is not given, the name of \"Doxyfile\" will be used"
 echo ""
 echo " $0 w           [ <DoxyFileName> ]"
 echo " $0 wizard      [ <DoxyFileName> ]"
 echo "       start the gui wizard to modify the doxyfile with name \"<DoxyFileName>\""
 echo "       if optional parameter <DoxyFileName>  is not given, the name of \"Doxyfile\" will be used"
 exit
}

function Wizard
{
 local Name=$1
 if [[ "$Name" == "" ]]; then
  Name=Doxyfile
 fi
# echo "Wizard( )                                                                              " 1>&2
# echo " Name:                                    \"$Name\"                                    " 1>&2
 doxywizard $Name
}

if [[ "$1" == "c" || "$1" == "create" ]]; then
 Create "$2"
# elif [[ "$1" == "g" || "$1" == "generate" ]]; then
#  Generate "$2"
elif [[ "$1" == "w" || "$1" == "wizard" ]]; then
 Wizard "$2"
else
 Usage
fi