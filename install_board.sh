#!/bin/bash

display_usage()
{ 
	echo -e "\nUsage:\n./install_board.sh <PATH TO PDK>\n" 
}

# if less than two arguments supplied, display usage 
if [ $# -ne 1 ] 
then 
	display_usage
	exit 1
fi

SCRIPTPATH="$( cd "$(dirname "$0")" ; pwd -P )"

echo "Copy new board files to path $1"
# copy starterware board
cp $SCRIPTPATH/src/am335x_coco.c $1/packages/ti/starterware/board/am335x/
cp $SCRIPTPATH/src/am335x_coco.h $1/packages/ti/starterware/board/am335x/
cp $SCRIPTPATH/src/am335x_coco_pinmux_data.c $1/packages/ti/starterware/board/am335x/

# copy board
cp -rf $SCRIPTPATH/src/cocoAM335x $1/packages/ti/board/src/

echo "Build PDK, recommended command:"
echo "# make clean && make LIMIT_SOCS="am335x" starterware_libs board_lib spi csl gpio uart i2c icss-emac profiling osal pruss"
