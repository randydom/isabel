include $(PROJECT_ROOT_DIR)/Makefile.head

SUBDIRS.PRE=
SUBDIRS.POST=

SCRIPTS:=\
	isabel_loop \
	isabel_fp \
	hostname \
	isabel.requires.sh \
	isabel_cleanup \
	isabel_scanner \
	shmkill

distrib::
	@mkdir -p $(DISTRIB_DIR)/isabelcore/bin
	@for i in $(SCRIPTS) ; do \
	  echo "$$i     --> $(DISTRIB_DIR)/isabelcore/bin"	;\
	  cp -rf $$i $(DISTRIB_DIR)/isabelcore/bin		;\
	  chmod a+x $(DISTRIB_DIR)/isabelcore/bin/$$i		;\
	done

include $(PROJECT_ROOT_DIR)/Makefile.tail
