#/bin/bash

REG='^//.veredit.version.*\|^//.creation.date.*\|^//.user.*:.*'

../veredit test3011.v -writeDot
diff -I $REG test3011.v.dot.OK test3011.v.dot

../veredit test3011.v -writeEdits
diff -I $REG test3011.v.edt.OK test3011.v.edt
../veredit test3011.v -writeEdits -leafCells -o  test3011.v.leafs.edt
diff -I $REG test3011.v.leafs.edt.OK test3011.v.leafs.edt


../veredit test.v test.edit
diff -I $REG test.v.new.OK test.v.new

../veredit test.v test2.edit -o test2.v.new
diff -I $REG test2.v.new.OK test2.v.new

# 1.2.0
../veredit test120.v test120.edit
diff -I $REG test120.v.new.OK test120.v.new

../veredit test120.v -install
diff -I $REG test120.v.install.OK test120.v.install

../veredit test120.v -ifspec -clk clk
diff -I $REG test120.v.ifspec.OK test120.v.ifspec

# 1.2.1
../veredit test121.v test121.edit
diff -I $REG test121.v.new.OK test121.v.new

../veredit test200.v test200.edit -ver
diff -I $REG test200.v.new.OK test200.v.new

# 2.0.0
../veredit test200.v -edt
diff -I $REG test200.v.edt_lib.OK test200.v.edt_lib

# 2.1.1
../veredit test211.v test211.edit
diff -I $REG test211.v.new.OK test211.v.new

# 2.1.2
../veredit test212.v -ver
diff -I $REG test212.v.new.OK test212.v.new

# 3.0.0
../veredit test300.v test300.edit -top c
diff -I $REG test300.v.new.OK test300.v.new

# 3.0.1
../veredit test301.v test301.edit -top c
diff -I $REG test301.v.new.OK test301.v.new

# 3.0.2
../veredit test302.v -top xbuffer -ver
diff -I $REG test302.v.new.OK test302.v.new

# 3.0.3
../veredit test303.v test303.edit
diff -I $REG test303.v.new.OK test303.v.new

# 3.0.4
../veredit test304.v test304.edit
diff -I $REG test304.v.new.OK test304.v.new

# 3.0.5
../veredit test305.v test305.edit
diff -I $REG test305.v.new.OK test305.v.new

# 3.0.8
../veredit test308.v test308.edit
diff -I $REG test308.v.new.OK test308.v.new

# 3.0.9
../veredit test309.v -expand -ver
diff -I $REG test309.v.new.OK test309.v.new

# 3.0.11
../veredit test3011.v -hier
diff -I $REG test3011.v.hier.OK test3011.v.hier
../veredit test3011.v -inst
diff -I $REG test3011.v.inst.OK test3011.v.inst

# 3.0.12
../veredit test3012.v test3012.edit
diff -I $REG test3012.v.new.OK test3012.v.new

# 3.0.13
../veredit test3013.v test3013.edit
diff -I $REG test3013.v.new.OK test3013.v.new

# 3.0.14
../veredit test3014.v test3014.edit
diff -I $REG test3014.v.new.OK test3014.v.new

