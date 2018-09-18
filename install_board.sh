#!/bin/bash

display_usage()
{ 
	echo -e "\nUsage:\n./install_board.sh <PDK VERSION [pdk_am335x_1_0_10, pdk_am335x_1_0_8]> <PATH TO PDK>\n" 
}

# if less than two arguments supplied, display usage 
if [ $# -ne 2 ] 
then 
	display_usage
	exit 1
fi

SCRIPTPATH="$( cd "$(dirname "$0")" ; pwd -P )"

echo "Copy new board files to path $2"
# copy starterware board
cp $SCRIPTPATH/$1/src/am335x_coco.c $2/packages/ti/starterware/board/am335x/
cp $SCRIPTPATH/$1/src/am335x_coco.h $2/packages/ti/starterware/board/am335x/
cp $SCRIPTPATH/$1/src/am335x_coco_pinmux_data.c $2/packages/ti/starterware/board/am335x/

# copy board
cp -rf $SCRIPTPATH/$1/src/cocoAM335x $2/packages/ti/board/src/

if [ $1 == "pdk_am335x_1_0_8" ]
then
	cp $SCRIPTPATH/$1/src/sorte_cocoam335x_app.cfg $2/packages/ti/drv/pruss/example/apps/sorte/src/
fi

echo "Build PDK, recommended command:"
echo "# make clean && make LIMIT_SOCS="am335x" starterware_libs board_lib spi csl gpio uart i2c icss-emac profiling osal pruss"
