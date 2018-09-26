## Create patch

Run command:
```
# make clean
# cd <PATH TO CLEAN PDK>/..
# find ./pdk_am335x_1_0_8/packages/ \( -name "*.mk" -o -name "*.bld" -o -name "*.h" -o -name "*.make" -o -name "*.c" -o -name "*.bat" -o -name "*.sh" -o -name "*makefile" \) -exec diff -Nau {} <PATH TO MODIFIED PDK>/{} \; > <PATH TO COCO BOARD REPO>/coco_board.patch
```

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

### Windows
Open a Linux terminal and execute the patch from the pdk root folder:
```
# cd /mnt/<...>/pdk_am335x_<version>/
# patch -p2 < <PATH TO REPO>/<PATCH NAME>.patch 
```
If a file fails, update manually the file.
Install the board following the steps of the install_board script manually.

## Build PDK
Open a new terminal and run the pdksetupenv script.
The script provided for TI, pdksetupenv, assumes that SDK install path is home in Linux and C:\ti in Windows. If it is different from that, this script needs to be adapted.
Build the PDK, recommended command:
```
# make clean && make -k all
```
(In Windows change make for gmake)
