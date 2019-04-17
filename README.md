## Apply the patch
### Linux
Execute the following commands from the pdk root folder:

	# find . -type f -print0 | xargs -0 dos2unix
	# patch -p2 < <PATH TO REPO>/<PATCH NAME>.patch 

Install the board running the script:

	# ./install_board.sh <PATH TO PDK>


#### Build PDK
Open a new terminal and run the pdksetupenv script.
The script provided for TI, pdksetupenv, assumes that SDK install path is home. If it is different from that, this the setupenv script needs to be adapted.
Build the PDK, recommended command:

	# make clean && make -k all


### Windows
1. Install [Ubuntu](https://tutorials.ubuntu.com/tutorial/tutorial-ubuntu-on-windows#0) and [patch](http://gnuwin32.sourceforge.net/packages/patch.htm) dependence 
2. Download and install PDK to default directory ( C:\ti )
    - [SDK RTOS 04.01.00.06](http://software-dl.ti.com/processor-sdk-rtos/esd/AM335X/04_01_00_06/index_FDS.html)
    - [SDK RTOS 04.03.00.05](http://software-dl.ti.com/processor-sdk-rtos/esd/AM335X/04_03_00_05/index_FDS.html)
    - [SDK RTOS 05.01.00.11](http://software-dl.ti.com/processor-sdk-rtos/esd/AM335X/05_01_00_11/index_FDS.html)
    
3. Open Ubuntu terminal and move to board path:

	 
	    # cd /mnt/c/Users/<Your User>/<Board Path>

    Run next command:

    	# cp src/common/cocoV1/am335x_coco.c /mnt/c/ti/pdk_am335x_1_0_8/packages/ti/starterware/board/am335x/ && cp src/common/cocoV1/am335x_coco.h /mnt/c/ti/pdk_am335x_1_0_8/packages/ti/starterware/board/am335x/ && cp src/common/cocoV1/am335x_coco_pinmux_data.c /mnt/c/ti/pdk_am335x_1_0_8/packages/ti/starterware/board/am335x/ && cp src/common/cocoV1/sorte_cocoam335x_app.cfg /mnt/c/ti/pdk_am335x_1_0_8/packages/ti/drv/pruss/example/apps/sorte/src/ && cp -rf src/common/cocoV1/cocoAM335x /mnt/c/ti/pdk_am335x_1_0_8/packages/ti/board/src
		# cp src/common/cocoV2/am335x_cocov2.c /mnt/c/ti/pdk_am335x_1_0_8/packages/ti/starterware/board/am335x/ && cp src/common/cocoV2/am335x_cocov2.h /mnt/c/ti/pdk_am335x_1_0_8/packages/ti/starterware/board/am335x/ && cp src/common/cocoV2/am335x_cocov2_pinmux_data.c /mnt/c/ti/pdk_am335x_1_0_8/packages/ti/starterware/board/am335x/ && cp src/common/cocoV2/sorte_cocov2am335x_app.cfg /mnt/c/ti/pdk_am335x_1_0_8/packages/ti/drv/pruss/example/apps/sorte/src/ && cp -rf src/common/cocoV2/cocoV2AM335x /mnt/c/ti/pdk_am335x_1_0_8/packages/ti/board/src
	    
5. Open a **windows command prompt** with permission to modify pdk installed folder (admin user), and move to pdk path folder, and run next commands:
	
		# cd C:\ti\pdk_am335x_1_0_8\
		# <PATH TO PATCH UTILITY>\patch.exe -p2 < <PATH TO REPO>/pdk_am335x_1_0_8_coco_board.patch

	Example:

		# "C:\Program Files (x86)\GnuWin32\bin\patch.exe" -p2 < C:\Users\MyUser\Documents\coco-bsp\pdk_am335x_1_0_12_coco_board.patch

    
5. Rebuild the pdk:


	    # cd C:\ti\pdk_am335x_1.0.8\packages && pdksetupenv.bat && gmake clean && gmake -j8


# Develop
## Create patch
### Linux
Run command:

	# make clean
	# cd <PATH TO CLEAN PDK>/..
	# find ./pdk_am335x_1_0_8/packages/ \( -name "*.mk" -o -name "*.bld" -o -name "*.h" -o -name "*.make" -o -name "*.c" -o -name "*.bat" -o -name "*.sh" -o -name "*makefile" \) -exec diff -Nau {} <PATH TO MODIFIED PDK>/{} \; > <PATH TO COCO BOARD REPO>/coco_board.patch

