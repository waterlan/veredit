all: veredit.txt veredit.html veredit.1 veredit.pdf

veredit.txt : veredit.pod
	pod2text $< > $@

veredit.html : veredit.pod
	pod2html --title="Veredit" $< > $@

veredit.1 : veredit.pod
	pod2man --center="$$(date "+%Y-%m-%d")" --name="veredit" --section="1" $< > $@

veredit.ps : veredit.1
	groff -man $< -T ps > $@

veredit.pdf : veredit.ps
	ps2pdf $< $@
