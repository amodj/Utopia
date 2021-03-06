XEN_ROOT = ../../../
include $(XEN_ROOT)/tools/Rules.mk

# Init scripts.
XEND_INITD = init.d/xend
XENDOMAINS_INITD = init.d/xendomains
XENDOMAINS_SYSCONFIG = init.d/sysconfig.xendomains

# Xen configuration dir and configs to go there.
XEN_CONFIG_DIR = /etc/xen

# Xen script dir and scripts to go there.
XEN_SCRIPT_DIR = /etc/xen/scripts
XEN_SCRIPTS = network-bridge vif-bridge
XEN_SCRIPTS += network-route vif-route
XEN_SCRIPTS += network-nat vif-nat
XEN_SCRIPTS += block
XEN_SCRIPTS += block-enbd block-nbd
XEN_SCRIPTS += vtpm vtpm-delete
XEN_SCRIPTS += xen-hotplug-cleanup
XEN_SCRIPTS += external-device-migrate
XEN_SCRIPTS += vscsi
XEN_SCRIPT_DATA = xen-script-common.sh locking.sh logging.sh
XEN_SCRIPT_DATA += xen-hotplug-common.sh xen-network-common.sh vif-common.sh
XEN_SCRIPT_DATA += block-common.sh vtpm-common.sh vtpm-hotplug-common.sh
XEN_SCRIPT_DATA += vtpm-migration.sh vtpm-impl

XEN_HOTPLUG_DIR = /etc/hotplug
XEN_HOTPLUG_SCRIPTS = xen-backend.agent

UDEV_RULES_DIR = /etc/udev
UDEV_RULES = xen-backend.rules xend.rules

DI = $(if $(DISTDIR),$(shell readlink -f $(DISTDIR)),)
DE = $(if $(DESTDIR),$(shell readlink -f $(DESTDIR)),)
ifeq ($(findstring $(DI),$(DE)),$(DI))
HOTPLUGS=install-hotplug install-udev
else
ifeq ($(shell [ -x /usr/bin/udevinfo ] && [ `/usr/bin/udevinfo -V | sed -e 's/^[^0-9]* \([0-9]\{1,\}\)[^0-9]\{0,\}/\1/'` -ge 059 ] && echo 1),1)
HOTPLUGS=install-udev
else
HOTPLUGS=install-hotplug
endif
endif

.PHONY: all
all:

.PHONY: build
build:

.PHONY: install
install: all install-initd install-scripts $(HOTPLUGS)

.PHONY: install-initd
install-initd:
	[ -d $(DESTDIR)/etc/init.d ] || $(INSTALL_DIR) $(DESTDIR)/etc/init.d
	[ -d $(DESTDIR)/etc/sysconfig ] || $(INSTALL_DIR) $(DESTDIR)/etc/sysconfig
	$(INSTALL_PROG) $(XEND_INITD) $(DESTDIR)/etc/init.d
	$(INSTALL_PROG) $(XENDOMAINS_INITD) $(DESTDIR)/etc/init.d
	$(INSTALL_PROG) $(XENDOMAINS_SYSCONFIG) $(DESTDIR)/etc/sysconfig/xendomains

.PHONY: install-scripts
install-scripts:
	[ -d $(DESTDIR)$(XEN_SCRIPT_DIR) ] || \
		$(INSTALL_DIR) $(DESTDIR)$(XEN_SCRIPT_DIR)
	set -e; for i in $(XEN_SCRIPTS); \
	    do \
	    $(INSTALL_PROG) $$i $(DESTDIR)$(XEN_SCRIPT_DIR); \
	done
	set -e; for i in $(XEN_SCRIPT_DATA); \
	    do \
	    $(INSTALL_DATA) $$i $(DESTDIR)$(XEN_SCRIPT_DIR); \
	done

.PHONY: install-hotplug
install-hotplug:
	[ -d $(DESTDIR)$(XEN_HOTPLUG_DIR) ] || \
		$(INSTALL_DIR) $(DESTDIR)$(XEN_HOTPLUG_DIR)
	set -e; for i in $(XEN_HOTPLUG_SCRIPTS); \
	    do \
	    $(INSTALL_PROG) $$i $(DESTDIR)$(XEN_HOTPLUG_DIR); \
	done

.PHONY: install-udev
install-udev:
	[ -d $(DESTDIR)$(UDEV_RULES_DIR) ] || \
		$(INSTALL_DIR) $(DESTDIR)$(UDEV_RULES_DIR)/rules.d
	set -e; for i in $(UDEV_RULES); \
	    do \
	    $(INSTALL_DATA) $$i $(DESTDIR)$(UDEV_RULES_DIR); \
	    ln -sf ../$$i $(DESTDIR)$(UDEV_RULES_DIR)/rules.d; \
	done

.PHONY: clean
clean:
