#!/bin/bash

../../veredit testbuf.v  testbuf.veredit -o testbuf.out.v -ver
diff testbuf.out.v.OK testbuf.out.v

../../veredit testobs.v testobs.veredit -ver -o  testobs.out.v
diff testobs.out.v.OK testobs.out.v
