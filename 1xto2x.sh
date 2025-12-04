case $# in
0)
    echo "- This scripts changes veredit 1.x scripts to veredit 2.x scripts."
	 echo "- Please check scripts afterwards."
    echo "- Usage: $0 <veredit script files>"
exit 0
;;
*)

 for i in $*
 do
 /bin/cp -p $i $i.orig
 sed \
 -e s/INSTANCE/-instance/g \
 -e 's/END ADDPORTS//g' \
 -e s/ADDPORTS/-addports/g \
 -e 's/END DELPORTS//g' \
 -e s/DELPORTS/-delports/g \
 -e 's/END RMPORTS//g' \
 -e s/RMPORTS/-rmports/g \
 -e 's/END ADDINST//g' \
 -e s/ADDINST/-addinst/g \
 -e 's/END DELINST//g' \
 -e s/DELINST/-delinst/g \
 -e 's/END ADDASSIGN//g' \
 -e s/ADDASSIGN/-addassign/g \
 -e 's/END DELASSIGN//g' \
 -e s/DELASSIGN/-delassign/g \
 -e s/DELETE/-delete/g \
 -e s/EXCLUDE/-exclude/g \
 -e s/BUFFEROUTPUTS/-bufferoutputs/g \
 -e s/REMOVEBUFFERS/-removebuffers/g \
 -e s/BUFFERLIST/-bufferlist/g \
 -e s/BUFFERINPUT/-bufferinput/g \
 -e 's/END BUFFER//g' \
 -e s/BUFFER/-buffer/g \
 -e s/INSERTOBSINPUT/-insertobsinput/g \
 -e s/OTHER/-other/g \
 -e s/NETS/-nets/g \
 -e s/INSERTOBSOUTPUT/-insertobsoutput/g \
 -e s/LISTINST/-listinst/g \
 -e s/NET/-net/g \
 -e s/TIECELL/-tiecell/g \
 -e s/OUTPUT/-output/g \
 -e 's/INPUT/-input/g' \
 -e s/END//g < $i > $i.tmp
 /bin/mv $i.tmp $i
 done

;;
esac


