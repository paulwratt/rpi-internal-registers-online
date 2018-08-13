# Register Region: AUX


##Info
| Name | value |
| --- | --- |
| base | 0x7E215000 |

##Registers

| register name | address | type | width | mask | reset |
| --- | --- | --- | --- | --- | --- |
| AUX_MU_IO | 0x7e215040 | MU_IO |  |  |  |
| AUX_MU_BDLS | 0x7e215040 | MU_BDLS |  |  |  |
| AUX_MU_IER | 0x7e215044 | MU_IER |  |  |  |
| AUX_MU_BDMS | 0x7e215044 | MU_BDMS |  |  |  |
| AUX_MU_IIR | 0x7e215048 | MU_IIR |  |  |  |
| AUX_MU_FCR | 0x7e215048 | MU_FCR |  |  |  |
| AUX_MU_LCR | 0x7e21504c | MU_LCR |  |  |  |
| AUX_MU_MCR | 0x7e215050 | MU_MCR |  |  |  |
| AUX_MU_LSR | 0x7e215054 | MU_LSR |  |  |  |
| AUX_MU_MSR | 0x7e215058 | MU_MSR |  |  |  |
| AUX_MU_CNTL | 0x7e215060 | MU_CNTL |  |  |  |
| AUX_MU_STAT | 0x7e215064 | MU_STAT |  |  |  |
| AUX_MU_BAUD | 0x7e215068 | MU_BAUD |  |  |  |
| AUX_SPI0_CNTL0 | 0x7e215080 | SPI0_CNTL0 |  |  |  |
| AUX_SPI0_CNTL1 | 0x7e215084 | SPI0_CNTL1 |  |  |  |
| AUX_SPI0_STAT | 0x7e215088 | SPI0_STAT |  |  |  |
| AUX_SPI0_PEEK | 0x7e21508c | SPI0_PEEK |  |  |  |
| AUX_SPI0_IO | 0x7e2150a0 | SPI0_IO |  |  |  |
| AUX_SPI0_TXHOLD | 0x7e2150b0 | SPI0_TXHOLD |  |  |  |
| AUX_SPI1_CNTL0 | 0x7e2150c0 | SPI1_CNTL0 |  |  |  |
| AUX_SPI1_CNTL1 | 0x7e2150c4 | SPI1_CNTL1 |  |  |  |
| AUX_SPI1_STAT | 0x7e2150c8 | SPI1_STAT |  |  |  |
| AUX_SPI1_PEEK | 0x7e2150cc | SPI1_PEEK |  |  |  |
| AUX_SPI1_IO | 0x7e2150e0 | SPI1_IO |  |  |  |
| AUX_SPI1_TXHOLD | 0x7e2150f0 | SPI1_TXHOLD |  |  |  |

##Unsupported defines

| define | value |
| --- | --- |
| AUX_ENABLES | 0x7e215004 |
| AUX_ENABLE_MINIUART | 0x01 |
| AUX_ENABLE_SPI0 | 0x02 |
| AUX_ENABLE_SPI1 | 0x04 |
| AUX_IO_BASE | 0x7E215000 |
| AUX_IRQ | 0x7e215000 |
| AUX_MU_CNTL_AUCTSINV | 0x80 |
| AUX_MU_CNTL_AURTRINV | 0x40 |
| AUX_MU_CNTL_AUTO_CTS | 0x08 |
| AUX_MU_CNTL_AUTO_RTR | 0x04 |
| AUX_MU_CNTL_FLOW1 | 0x20 |
| AUX_MU_CNTL_FLOW2 | 0x10 |
| AUX_MU_CNTL_FLOW3 | 0x00 |
| AUX_MU_CNTL_FLOW4 | 0x30 |
| AUX_MU_CNTL_REC_ENBL | 0x01 |
| AUX_MU_CNTL_TRN_ENBL | 0x02 |
| AUX_MU_FCR_RXCLR | 0x02 |
| AUX_MU_FCR_TXCLR | 0x04 |
| AUX_MU_IER_RXIRQEN | 0x01 |
| AUX_MU_IER_TXIRQEN | 0x02 |
| AUX_MU_IIR_IRQ | 0x06 |
| AUX_MU_IIR_NOIRQS | 0x01 |
| AUX_MU_LCR_7BITS | 0x02 |
| AUX_MU_LCR_8BITS | 0x03 |
| AUX_MU_LCR_BREAK | 0x40 |
| AUX_MU_LCR_DLAB | 0x80 |
| AUX_MU_LSR_DR | 0x01 |
| AUX_MU_LSR_OE | 0x02 |
| AUX_MU_LSR_TEMT | 0x40 |
| AUX_MU_LSR_THRE | 0x20 |
| AUX_MU_MCR_RTS | 0x02 |
| AUX_MU_MSR_CTS | 0x10 |
| AUX_MU_SCRATCH | 0x7e21505c |
| AUX_MU_STAT_CTS | 0x00000080 |
| AUX_MU_STAT_RTR | 0x00000040 |
| AUX_MU_STAT_RXFILL | 0x00FF0000 |
| AUX_MU_STAT_RX_DATA | 0x00000001 |
| AUX_MU_STAT_RX_IDLE | 0x00000004 |
| AUX_MU_STAT_RX_OFLW | 0x00000010 |
| AUX_MU_STAT_TXDONE | 0x00000200 |
| AUX_MU_STAT_TXEMPTY | 0x00000100 |
| AUX_MU_STAT_TXFILL | 0xFF000000 |
| AUX_MU_STAT_TX_FULL | 0x00000020 |
| AUX_MU_STAT_TX_IDLE | 0x00000008 |
| AUX_MU_STAT_TX_SPACE | 0x00000002 |
| AUX_SPI_CNTL0_BITS | 0x0000003F |
| AUX_SPI_CNTL0_CS0_N | 0x000C0000 |
| AUX_SPI_CNTL0_CS1_N | 0x000A0000 |
| AUX_SPI_CNTL0_CS2_N | 0x00060000 |
| AUX_SPI_CNTL0_CSA_N | 0x00000000 |
| AUX_SPI_CNTL0_CSFROMFF | 0x00008000 |
| AUX_SPI_CNTL0_CS_HIGH | 0x000E0000 |
| AUX_SPI_CNTL0_FFCLR | 0x00000200 |
| AUX_SPI_CNTL0_HOLD0 | 0x00000000 |
| AUX_SPI_CNTL0_HOLD10 | 0x00003000 |
| AUX_SPI_CNTL0_HOLD4 | 0x00001000 |
| AUX_SPI_CNTL0_HOLD7 | 0x00002000 |
| AUX_SPI_CNTL0_INFALL | 0x00000000 |
| AUX_SPI_CNTL0_INRISE | 0x00000400 |
| AUX_SPI_CNTL0_INVCLK | 0x00000080 |
| AUX_SPI_CNTL0_OUTFALL | 0x00000000 |
| AUX_SPI_CNTL0_OUTMS | 0x00000040 |
| AUX_SPI_CNTL0_OUTRISE | 0x00000100 |
| AUX_SPI_CNTL0_POSTIN | 0x00010000 |
| AUX_SPI_CNTL0_SERENBL | 0x00000800 |
| AUX_SPI_CNTL0_SPEED | 0xFFF00000 |
| AUX_SPI_CNTL0_SPEEDSHFT | 20 |
| AUX_SPI_CNTL0_VARWID | 0x00004000 |
| AUX_SPI_CNTL1_CSPLUS1 | 0x00000100 |
| AUX_SPI_CNTL1_CSPLUS2 | 0x00000200 |
| AUX_SPI_CNTL1_CSPLUS3 | 0x00000300 |
| AUX_SPI_CNTL1_CSPLUS4 | 0x00000400 |
| AUX_SPI_CNTL1_CSPLUS5 | 0x00000500 |
| AUX_SPI_CNTL1_CSPLUS6 | 0x00000600 |
| AUX_SPI_CNTL1_CSPLUS7 | 0x00000700 |
| AUX_SPI_CNTL1_DONEIRQ | 0x00000080 |
| AUX_SPI_CNTL1_EMPTYIRQ | 0x00000040 |
| AUX_SPI_CNTL1_HOLDIN | 0x00000001 |
| AUX_SPI_CNTL1_INMS | 0x00000002 |
| AUX_SPI_STAT_BITCNT | 0x0000003F |
| AUX_SPI_STAT_BUSY | 0x00000040 |
| AUX_SPI_STAT_RXEMPTY | 0x00000080 |
| AUX_SPI_STAT_RXFILL | 0x000F0000 |
| AUX_SPI_STAT_RXFULL | 0x00000100 |
| AUX_SPI_STAT_TXEMPTY | 0x00000200 |
| AUX_SPI_STAT_TXFILL | 0x0F000000 |
| AUX_SPI_STAT_TXFULL | 0x00000400 |

##Register info
