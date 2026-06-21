#!/bin/bash

REG='^//.veredit.version.*\|^//.creation.date.*\|^//.user.*:.*'

../../veredit testtie.v testtie1.veredit -o testtie1.out.v
diff -I $REG testtie1.out.v.OK testtie1.out.v
../../veredit testtie.v testtie2.veredit -o testtie2.out.v
diff -I $REG testtie2.out.v.OK testtie2.out.v

