## Apply the patch
### Linux
Execute the following commands from the pdk root folder:
	```
	# find . -type f -print0 | xargs -0 dos2unix
	# patch -p2 < <PATH TO REPO>/<PATCH NAME>.patch 
	```
Install the board running the script:
	```
	# ./install_board.sh <PATH TO PDK>
	```

#### Build PDK
Open a new terminal and run the pdksetupenv script.
The script provided for TI, pdksetupenv, assumes that SDK install path is home in Linux and C:\ti in Windows. If it is different from that, this script needs to be adapted.
Build the PDK, recommended command:
	```
	# make clean && make -k all
	```

### Windows
1. Install [Ubuntu](https://tutorials.ubuntu.com/tutorial/tutorial-ubuntu-on-windows#0) dependence 
2. Download and install PDK to default directory ( C:\ti )
    EtherCAT - [SDK RTOS 04.01.00](http://processors.wiki.ti.com/index.php?title=Processor_SDK_RTOS_Release_Notes&oldid=231132)
    - AM335x PDK 1.0.8
    - XDC tools 3.32.01.22
    - SYSBIOS 6.46.05.55
    - NDK 2.25.01.11
    - EDMA 2.12.05.29

    [Download](http://software-dl.ti.com/processor-sdk-rtos/esd/AM335X/04_01_00_06/index_FDS.html)
    
3. Open Ubuntu terminal and move to board path:

	    ```
	    # cd /mnt/c/Users/<Your User>/<Board Path>
	    ```
    Run next command:

	    ```
	    # cp src/common/am335x_coco.c /mnt/c/ti/pdk_am335x_1_0_8/packages/ti/starterware/board/am335x/ && cp src/common/am335x_coco.h /mnt/c/ti/pdk_am335x_1_0_8/packages/ti/starterware/board/am335x/ && cp src/common/am335x_coco_pinmux_data.c /mnt/c/ti/pdk_am335x_1_0_8/packages/ti/starterware/board/am335x/ && cp src/common/sorte_cocoam335x_app.cfg /mnt/c/ti/pdk_am335x_1_0_8/packages/ti/drv/pruss/example/apps/sorte/src/ && cp -rf src/common/cocoAM335x /mnt/c/ti/pdk_am335x_1_0_8/packages/ti/board/src
	    ```
    
4. Replace <PATH TO BOARD> to the local path to board folder, and run next commands:
	
	    ```
	    # cd /mnt/c/ti/pdk_am335x_1_0_8/
	    # patch -p2 --binary < <PATH TO REPO>/pdk_am335x_1_0_8_coco_board.patch && patch -p2 < <PATH TO REPO>/pdk_am335x_1_0_8_coco_board.patch
	    ```
    
5. Open a windows command prompt and run:

	    ```
	    # cd C:\ti\pdk_am335x_1.0.8\packages && pdksetupenv.bat && gmake clean && gmake -j8
	    ```

# Develop
## Create patch
### Linux
Run command:
	```
	# make clean
	# cd <PATH TO CLEAN PDK>/..
	# find ./pdk_am335x_1_0_8/packages/ \( -name "*.mk" -o -name "*.bld" -o -name "*.h" -o -name "*.make" -o -name "*.c" -o -name "*.bat" -o -name "*.sh" -o -name "*makefile" \) -exec diff -Nau {} <PATH TO MODIFIED PDK>/{} \; > <PATH TO COCO BOARD REPO>/coco_board.patch
	```
