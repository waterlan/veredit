VERSION = 3.0.19

dist:
	cd ..; git archive --prefix=veredit-$(VERSION)/ --format tar.gz -o veredit-$(VERSION).tar.gz HEAD

tag:
	cd ..; git tag -a veredit-$(VERSION) -m "Tagging veredit release $(VERSION)."
	cd ..; git push origin veredit-$(VERSION)
