#!/bin/bash

set -e

dot -Tpdf -Gsize="7.5,10" $1 > $1.pdf
evince $1.pdf

