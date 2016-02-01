# kgdboe

A DKMS version of KGDBOE from
http://sysprogs.com/VisualKernel/kgdboe/

You can get the deb package directly and install by dpkg -i.
This version of KGDBOE can be used without re-compiling kernel for set_memory_rw is not exported in kernel >= 4.1.

It makes life easier to debug a native OS kernel.
Ubuntu 3.19/4.2 kernel is tested OK with this KGDBOE.
