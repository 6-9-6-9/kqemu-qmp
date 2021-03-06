#ifndef HW_IDE_H
#define HW_IDE_H

#include "isa.h"
#include "pci.h"

/* ide-isa.c */
ISADevice *isa_ide_init(int iobase, int iobase2, int isairq,
                        DriveInfo *hd0, DriveInfo *hd1);

/* ide-pci.c */
void pci_cmd646_ide_init(PCIBus *bus, DriveInfo **hd_table,
                         int secondary_ide_enabled);
PCIDevice *pci_piix3_ide_init(PCIBus *bus, DriveInfo **hd_table, int devfn);
PCIDevice *pci_piix4_ide_init(PCIBus *bus, DriveInfo **hd_table, int devfn);

/* ide-macio.c */
int pmac_ide_init (DriveInfo **hd_table, qemu_irq irq,
		   void *dbdma, int channel, qemu_irq dma_irq);

/* ide-mmio.c */
void mmio_ide_init (target_phys_addr_t membase, target_phys_addr_t membase2,
                    qemu_irq irq, int shift,
                    DriveInfo *hd0, DriveInfo *hd1);

void ide_get_bs(BlockDriverState *bs[], BusState *qbus);

#endif /* HW_IDE_H */
