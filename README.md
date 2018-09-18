## Create patch

Run command:
```
# make clean
# cd <PATH TO CLEAN PDK>/..
# find ./pdk_am335x_1_0_8/packages/ \( -name "*.mk" -o -name "*.bld" -o -name "*.h" -o -name "*.make" -o -name "*.c" -o -name "*.bat" -o -name "*.sh" -o -name "*makefile" \) -exec diff -Nau {} <PATH TO MODIFIED PDK>/{} \; > <PATH TO COCO BOARD REPO>/coco_board.patch
```

## Apply the patch

Run command:
```
find . -type f -print0 | xargs -0 dos2unix
# patch -p2 < <PATH TO REPO>/<PATCH NAME>.patch 
```

## Build PDK

The script provided for TI, pdksetupenv, assume that SDK install path is home in linux and C:\ in windows. If it is different from that, this script neeed to be adapted. 