#define KVA      0xffff000000000000
#define MMIO_BASE (KVA + 0x3f000000)

//# define MMIO_BASE       0x3F000000

# define CORE0_TIMER_IRQ_CTRL  0x40000040
# define CORE1_TIMER_IRQ_CTRL  0x40000044
# define CORE2_TIMER_IRQ_CTRL  0x40000048
# define CORE3_TIMER_IRQ_CTRL  0x4000004C

# define IRQ_BASE             (MMIO_BASE + 0xb000)

# define IRQ_BASIC_PENDING    (IRQ_BASE + 0x200)

# define CORE0_INTR_SRC        0x40000060
# define CORE1_INTR_SRC        0x40000064
# define CORE2_INTR_SRC        0x40000068
# define CORE3_INTR_SRC        0x4000006C
