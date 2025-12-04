VERSION = 3.0.19

OBJ = \
 veredit-$(VERSION)/veredit \
 veredit-$(VERSION)/veredit.1 \
 veredit-$(VERSION)/veredit.txt \
 veredit-$(VERSION)/veredit.pdf \
 veredit-$(VERSION)/veredit.pod \
 veredit-$(VERSION)/ChangeLog.txt \
 veredit-$(VERSION)/COPYING.txt \
 veredit-$(VERSION)/README.md \
 veredit-$(VERSION)/testdir \

all:
	@echo "tag:        tag archive"
	@echo "dist:       create source tar ball of tag"
	@echo "disthead:   create source tar ball of current HEAD"
	@echo "bin:        create binary package"
tag:
	cd ..; git tag -a veredit-$(VERSION) -m "Tagging veredit release $(VERSION)."
	cd ..; git push origin veredit-$(VERSION)

dist:
	cd ..; git archive --prefix=veredit-$(VERSION)/ --format tar.gz -o veredit-$(VERSION).tar.gz veredit-$(VERSION)

disthead:
	cd ..; git archive --prefix=veredit-head/ --format tar.gz -o veredit-head.tar.gz HEAD

bin:
	cd ..; tar xaf veredit-$(VERSION).tar.gz
	cd ../veredit-$(VERSION); ./Compile
	cd ..; tar caf veredit-linux-x86_64-$(VERSION).tar.gz $(OBJ)
