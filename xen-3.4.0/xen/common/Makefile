obj-y += bitmap.o
obj-y += domctl.o
obj-y += domain.o
obj-y += event_channel.o
obj-y += grant_table.o
obj-y += kernel.o
obj-y += keyhandler.o
obj-y += kexec.o
obj-y += lib.o
obj-y += memory.o
obj-y += multicall.o
obj-y += page_alloc.o
obj-y += rangeset.o
obj-y += sched_credit.o
obj-y += sched_sedf.o
obj-y += schedule.o
obj-y += shutdown.o
obj-y += softirq.o
obj-y += spinlock.o
obj-y += stop_machine.o
obj-y += string.o
obj-y += symbols.o
obj-y += sysctl.o
obj-y += time.o
obj-y += timer.o
obj-y += trace.o
obj-y += version.o
obj-y += vsprintf.o
obj-y += xmalloc_tlsf.o
obj-y += rcupdate.o

obj-$(perfc)       += perfc.o
obj-$(crash_debug) += gdbstub.o
obj-$(xenoprof)    += xenoprof.o

obj-$(CONFIG_XENCOMM) += xencomm.o

subdir-$(CONFIG_COMPAT) += compat

subdir-$(x86_32) += hvm
subdir-$(x86_64) += hvm
subdir-$(ia64) += hvm

subdir-y += libelf
