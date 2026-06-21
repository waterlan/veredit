#!/bin/bash

REG='^//.veredit.version.*\|^//.creation.date.*\|^//.user.*:.*'

../../veredit testbuf.v  testbuf.veredit -o testbuf.out.v -ver
diff -I $REG testbuf.out.v.OK testbuf.out.v

../../veredit testobs.v testobs.veredit -ver -o  testobs.out.v
diff -I $REG testobs.out.v.OK testobs.out.v
