# spm-decomp
A Work-in-Progress decompilation of the NTSC-U rev 0 version of Super Paper Mario. Since it's currently in its early stage, The code is injected in-game using Seeky's REL Loader (https://github.com/SeekyCt/spm-rel-loader/), but once the decomp gets accurate enough I may update some stuff to make it compile on its own.

The goal of this decomp is to make SPM modding easier by effectively dealing with C++ code rather than raw PowerPC, and to further increase my knowledge in reverse engineering and the C++ language.

To build this, download the SPM REL Loader and extract this repo in `spm-rel-loader\rel`, then build using the command `make us0`. This should produce a file named `spm.us0.rel`. Then, follow the instructions of the REL Loader.

## Credits
Credits to PistonMiner, Zephiles and Seeky for making the SPM REL Loader, and Seeky for teaching me a lot of this stuff.
