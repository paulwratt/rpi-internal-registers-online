// This file was generated by the create_regs script
#define APERF1_BASE                                              0x7ee08000
#define APERF1_APB_ID                                            0x41584950
#define APERF1_GEN_CTRL                                          HW_REGISTER_RW( 0x7ee08000 ) 
   #define APERF1_GEN_CTRL_MASK                                  0x00000003
   #define APERF1_GEN_CTRL_WIDTH                                 2
   #define APERF1_GEN_CTRL_RESET                                 0000000000
      #define APERF1_GEN_CTRL_ENABLE_BITS                        0:0
      #define APERF1_GEN_CTRL_ENABLE_SET                         0x00000001
      #define APERF1_GEN_CTRL_ENABLE_CLR                         0xfffffffe
      #define APERF1_GEN_CTRL_ENABLE_MSB                         0
      #define APERF1_GEN_CTRL_ENABLE_LSB                         0
      #define APERF1_GEN_CTRL_ENABLE_RESET                       0x0
      #define APERF1_GEN_CTRL_RESET_BITS                         1:1
      #define APERF1_GEN_CTRL_RESET_SET                          0x00000002
      #define APERF1_GEN_CTRL_RESET_CLR                          0xfffffffd
      #define APERF1_GEN_CTRL_RESET_MSB                          1
      #define APERF1_GEN_CTRL_RESET_LSB                          1
      #define APERF1_GEN_CTRL_RESET_RESET                        0x0
#define APERF1_BW0_CTRL                                          HW_REGISTER_RW( 0x7ee08040 ) 
   #define APERF1_BW0_CTRL_MASK                                  0xf0001f1f
   #define APERF1_BW0_CTRL_WIDTH                                 32
   #define APERF1_BW0_CTRL_RESET                                 0000000000
      #define APERF1_BW0_CTRL_BUS_BITS                           4:0
      #define APERF1_BW0_CTRL_BUS_SET                            0x0000001f
      #define APERF1_BW0_CTRL_BUS_CLR                            0xffffffe0
      #define APERF1_BW0_CTRL_BUS_MSB                            4
      #define APERF1_BW0_CTRL_BUS_LSB                            0
      #define APERF1_BW0_CTRL_BUS_RESET                          0x0
      #define APERF1_BW0_CTRL_ID_BITS                            12:8
      #define APERF1_BW0_CTRL_ID_SET                             0x00001f00
      #define APERF1_BW0_CTRL_ID_CLR                             0xffffe0ff
      #define APERF1_BW0_CTRL_ID_MSB                             12
      #define APERF1_BW0_CTRL_ID_LSB                             8
      #define APERF1_BW0_CTRL_ID_RESET                           0x0
      #define APERF1_BW0_CTRL_LATHALT_BITS                       28:28
      #define APERF1_BW0_CTRL_LATHALT_SET                        0x10000000
      #define APERF1_BW0_CTRL_LATHALT_CLR                        0xefffffff
      #define APERF1_BW0_CTRL_LATHALT_MSB                        28
      #define APERF1_BW0_CTRL_LATHALT_LSB                        28
      #define APERF1_BW0_CTRL_LATHALT_RESET                      0x0
      #define APERF1_BW0_CTRL_ID_EN_BITS                         29:29
      #define APERF1_BW0_CTRL_ID_EN_SET                          0x20000000
      #define APERF1_BW0_CTRL_ID_EN_CLR                          0xdfffffff
      #define APERF1_BW0_CTRL_ID_EN_MSB                          29
      #define APERF1_BW0_CTRL_ID_EN_LSB                          29
      #define APERF1_BW0_CTRL_ID_EN_RESET                        0x0
      #define APERF1_BW0_CTRL_EN_BITS                            30:30
      #define APERF1_BW0_CTRL_EN_SET                             0x40000000
      #define APERF1_BW0_CTRL_EN_CLR                             0xbfffffff
      #define APERF1_BW0_CTRL_EN_MSB                             30
      #define APERF1_BW0_CTRL_EN_LSB                             30
      #define APERF1_BW0_CTRL_EN_RESET                           0x0
      #define APERF1_BW0_CTRL_RESET_BITS                         31:31
      #define APERF1_BW0_CTRL_RESET_SET                          0x80000000
      #define APERF1_BW0_CTRL_RESET_CLR                          0x7fffffff
      #define APERF1_BW0_CTRL_RESET_MSB                          31
      #define APERF1_BW0_CTRL_RESET_LSB                          31
      #define APERF1_BW0_CTRL_RESET_RESET                        0x0
#define APERF1_BW0_ATRANS                                        HW_REGISTER_RO( 0x7ee08044 ) 
   #define APERF1_BW0_ATRANS_MASK                                0xffffffff
   #define APERF1_BW0_ATRANS_WIDTH                               32
   #define APERF1_BW0_ATRANS_RESET                               0000000000
#define APERF1_BW0_ATWAIT                                        HW_REGISTER_RO( 0x7ee08048 ) 
   #define APERF1_BW0_ATWAIT_MASK                                0xffffffff
   #define APERF1_BW0_ATWAIT_WIDTH                               32
   #define APERF1_BW0_ATWAIT_RESET                               0000000000
#define APERF1_BW0_AMAX                                          HW_REGISTER_RO( 0x7ee0804c ) 
   #define APERF1_BW0_AMAX_MASK                                  0x00ffffff
   #define APERF1_BW0_AMAX_WIDTH                                 24
   #define APERF1_BW0_AMAX_RESET                                 0000000000
#define APERF1_BW0_WTRANS                                        HW_REGISTER_RO( 0x7ee08050 ) 
   #define APERF1_BW0_WTRANS_MASK                                0xffffffff
   #define APERF1_BW0_WTRANS_WIDTH                               32
   #define APERF1_BW0_WTRANS_RESET                               0000000000
#define APERF1_BW0_WTWAIT                                        HW_REGISTER_RO( 0x7ee08054 ) 
   #define APERF1_BW0_WTWAIT_MASK                                0xffffffff
   #define APERF1_BW0_WTWAIT_WIDTH                               32
   #define APERF1_BW0_WTWAIT_RESET                               0000000000
#define APERF1_BW0_WMAX                                          HW_REGISTER_RO( 0x7ee08058 ) 
   #define APERF1_BW0_WMAX_MASK                                  0x00ffffff
   #define APERF1_BW0_WMAX_WIDTH                                 24
   #define APERF1_BW0_WMAX_RESET                                 0000000000
#define APERF1_BW0_RTRANS                                        HW_REGISTER_RO( 0x7ee0805c ) 
   #define APERF1_BW0_RTRANS_MASK                                0xffffffff
   #define APERF1_BW0_RTRANS_WIDTH                               32
   #define APERF1_BW0_RTRANS_RESET                               0000000000
#define APERF1_BW0_RTWAIT                                        HW_REGISTER_RO( 0x7ee08060 ) 
   #define APERF1_BW0_RTWAIT_MASK                                0xffffffff
   #define APERF1_BW0_RTWAIT_WIDTH                               32
   #define APERF1_BW0_RTWAIT_RESET                               0000000000
#define APERF1_BW0_RMAX                                          HW_REGISTER_RO( 0x7ee08064 ) 
   #define APERF1_BW0_RMAX_MASK                                  0x00ffffff
   #define APERF1_BW0_RMAX_WIDTH                                 24
   #define APERF1_BW0_RMAX_RESET                                 0000000000
#define APERF1_BW0_RPEND                                         HW_REGISTER_RO( 0x7ee08068 ) 
   #define APERF1_BW0_RPEND_MASK                                 0x000000ff
   #define APERF1_BW0_RPEND_WIDTH                                8
   #define APERF1_BW0_RPEND_RESET                                0000000000
#define APERF1_BW1_CTRL                                          HW_REGISTER_RW( 0x7ee08080 ) 
   #define APERF1_BW1_CTRL_MASK                                  0xf0001f1f
   #define APERF1_BW1_CTRL_WIDTH                                 32
   #define APERF1_BW1_CTRL_RESET                                 0000000000
      #define APERF1_BW1_CTRL_BUS_BITS                           4:0
      #define APERF1_BW1_CTRL_BUS_SET                            0x0000001f
      #define APERF1_BW1_CTRL_BUS_CLR                            0xffffffe0
      #define APERF1_BW1_CTRL_BUS_MSB                            4
      #define APERF1_BW1_CTRL_BUS_LSB                            0
      #define APERF1_BW1_CTRL_BUS_RESET                          0x0
      #define APERF1_BW1_CTRL_ID_BITS                            12:8
      #define APERF1_BW1_CTRL_ID_SET                             0x00001f00
      #define APERF1_BW1_CTRL_ID_CLR                             0xffffe0ff
      #define APERF1_BW1_CTRL_ID_MSB                             12
      #define APERF1_BW1_CTRL_ID_LSB                             8
      #define APERF1_BW1_CTRL_ID_RESET                           0x0
      #define APERF1_BW1_CTRL_LATHALT_BITS                       28:28
      #define APERF1_BW1_CTRL_LATHALT_SET                        0x10000000
      #define APERF1_BW1_CTRL_LATHALT_CLR                        0xefffffff
      #define APERF1_BW1_CTRL_LATHALT_MSB                        28
      #define APERF1_BW1_CTRL_LATHALT_LSB                        28
      #define APERF1_BW1_CTRL_LATHALT_RESET                      0x0
      #define APERF1_BW1_CTRL_ID_EN_BITS                         29:29
      #define APERF1_BW1_CTRL_ID_EN_SET                          0x20000000
      #define APERF1_BW1_CTRL_ID_EN_CLR                          0xdfffffff
      #define APERF1_BW1_CTRL_ID_EN_MSB                          29
      #define APERF1_BW1_CTRL_ID_EN_LSB                          29
      #define APERF1_BW1_CTRL_ID_EN_RESET                        0x0
      #define APERF1_BW1_CTRL_EN_BITS                            30:30
      #define APERF1_BW1_CTRL_EN_SET                             0x40000000
      #define APERF1_BW1_CTRL_EN_CLR                             0xbfffffff
      #define APERF1_BW1_CTRL_EN_MSB                             30
      #define APERF1_BW1_CTRL_EN_LSB                             30
      #define APERF1_BW1_CTRL_EN_RESET                           0x0
      #define APERF1_BW1_CTRL_RESET_BITS                         31:31
      #define APERF1_BW1_CTRL_RESET_SET                          0x80000000
      #define APERF1_BW1_CTRL_RESET_CLR                          0x7fffffff
      #define APERF1_BW1_CTRL_RESET_MSB                          31
      #define APERF1_BW1_CTRL_RESET_LSB                          31
      #define APERF1_BW1_CTRL_RESET_RESET                        0x0
#define APERF1_BW1_ATRANS                                        HW_REGISTER_RO( 0x7ee08084 ) 
   #define APERF1_BW1_ATRANS_MASK                                0xffffffff
   #define APERF1_BW1_ATRANS_WIDTH                               32
   #define APERF1_BW1_ATRANS_RESET                               0000000000
#define APERF1_BW1_ATWAIT                                        HW_REGISTER_RO( 0x7ee08088 ) 
   #define APERF1_BW1_ATWAIT_MASK                                0xffffffff
   #define APERF1_BW1_ATWAIT_WIDTH                               32
   #define APERF1_BW1_ATWAIT_RESET                               0000000000
#define APERF1_BW1_AMAX                                          HW_REGISTER_RO( 0x7ee0808c ) 
   #define APERF1_BW1_AMAX_MASK                                  0x00ffffff
   #define APERF1_BW1_AMAX_WIDTH                                 24
   #define APERF1_BW1_AMAX_RESET                                 0000000000
#define APERF1_BW1_WTRANS                                        HW_REGISTER_RO( 0x7ee08090 ) 
   #define APERF1_BW1_WTRANS_MASK                                0xffffffff
   #define APERF1_BW1_WTRANS_WIDTH                               32
   #define APERF1_BW1_WTRANS_RESET                               0000000000
#define APERF1_BW1_WTWAIT                                        HW_REGISTER_RO( 0x7ee08094 ) 
   #define APERF1_BW1_WTWAIT_MASK                                0xffffffff
   #define APERF1_BW1_WTWAIT_WIDTH                               32
   #define APERF1_BW1_WTWAIT_RESET                               0000000000
#define APERF1_BW1_WMAX                                          HW_REGISTER_RO( 0x7ee08098 ) 
   #define APERF1_BW1_WMAX_MASK                                  0x0000ffff
   #define APERF1_BW1_WMAX_WIDTH                                 16
   #define APERF1_BW1_WMAX_RESET                                 0000000000
#define APERF1_BW1_RTRANS                                        HW_REGISTER_RO( 0x7ee0809c ) 
   #define APERF1_BW1_RTRANS_MASK                                0xffffffff
   #define APERF1_BW1_RTRANS_WIDTH                               32
   #define APERF1_BW1_RTRANS_RESET                               0000000000
#define APERF1_BW1_RTWAIT                                        HW_REGISTER_RO( 0x7ee080a0 ) 
   #define APERF1_BW1_RTWAIT_MASK                                0xffffffff
   #define APERF1_BW1_RTWAIT_WIDTH                               32
   #define APERF1_BW1_RTWAIT_RESET                               0000000000
#define APERF1_BW1_RMAX                                          HW_REGISTER_RO( 0x7ee080a4 ) 
   #define APERF1_BW1_RMAX_MASK                                  0x00ffffff
   #define APERF1_BW1_RMAX_WIDTH                                 24
   #define APERF1_BW1_RMAX_RESET                                 0000000000
#define APERF1_BW1_RPEND                                         HW_REGISTER_RO( 0x7ee08068 ) 
   #define APERF1_BW1_RPEND_MASK                                 0x000000ff
   #define APERF1_BW1_RPEND_WIDTH                                8
   #define APERF1_BW1_RPEND_RESET                                0000000000
#define APERF1_BW2_CTRL                                          HW_REGISTER_RW( 0x7ee080c0 ) 
   #define APERF1_BW2_CTRL_MASK                                  0xf0001f1f
   #define APERF1_BW2_CTRL_WIDTH                                 32
   #define APERF1_BW2_CTRL_RESET                                 0000000000
      #define APERF1_BW2_CTRL_BUS_BITS                           4:0
      #define APERF1_BW2_CTRL_BUS_SET                            0x0000001f
      #define APERF1_BW2_CTRL_BUS_CLR                            0xffffffe0
      #define APERF1_BW2_CTRL_BUS_MSB                            4
      #define APERF1_BW2_CTRL_BUS_LSB                            0
      #define APERF1_BW2_CTRL_BUS_RESET                          0x0
      #define APERF1_BW2_CTRL_ID_BITS                            12:8
      #define APERF1_BW2_CTRL_ID_SET                             0x00001f00
      #define APERF1_BW2_CTRL_ID_CLR                             0xffffe0ff
      #define APERF1_BW2_CTRL_ID_MSB                             12
      #define APERF1_BW2_CTRL_ID_LSB                             8
      #define APERF1_BW2_CTRL_ID_RESET                           0x0
      #define APERF1_BW2_CTRL_LATHALT_BITS                       28:28
      #define APERF1_BW2_CTRL_LATHALT_SET                        0x10000000
      #define APERF1_BW2_CTRL_LATHALT_CLR                        0xefffffff
      #define APERF1_BW2_CTRL_LATHALT_MSB                        28
      #define APERF1_BW2_CTRL_LATHALT_LSB                        28
      #define APERF1_BW2_CTRL_LATHALT_RESET                      0x0
      #define APERF1_BW2_CTRL_ID_EN_BITS                         29:29
      #define APERF1_BW2_CTRL_ID_EN_SET                          0x20000000
      #define APERF1_BW2_CTRL_ID_EN_CLR                          0xdfffffff
      #define APERF1_BW2_CTRL_ID_EN_MSB                          29
      #define APERF1_BW2_CTRL_ID_EN_LSB                          29
      #define APERF1_BW2_CTRL_ID_EN_RESET                        0x0
      #define APERF1_BW2_CTRL_EN_BITS                            30:30
      #define APERF1_BW2_CTRL_EN_SET                             0x40000000
      #define APERF1_BW2_CTRL_EN_CLR                             0xbfffffff
      #define APERF1_BW2_CTRL_EN_MSB                             30
      #define APERF1_BW2_CTRL_EN_LSB                             30
      #define APERF1_BW2_CTRL_EN_RESET                           0x0
      #define APERF1_BW2_CTRL_RESET_BITS                         31:31
      #define APERF1_BW2_CTRL_RESET_SET                          0x80000000
      #define APERF1_BW2_CTRL_RESET_CLR                          0x7fffffff
      #define APERF1_BW2_CTRL_RESET_MSB                          31
      #define APERF1_BW2_CTRL_RESET_LSB                          31
      #define APERF1_BW2_CTRL_RESET_RESET                        0x0
#define APERF1_BW2_ATRANS                                        HW_REGISTER_RO( 0x7ee080c4 ) 
   #define APERF1_BW2_ATRANS_MASK                                0xffffffff
   #define APERF1_BW2_ATRANS_WIDTH                               32
   #define APERF1_BW2_ATRANS_RESET                               0000000000
#define APERF1_BW2_ATWAIT                                        HW_REGISTER_RO( 0x7ee080c8 ) 
   #define APERF1_BW2_ATWAIT_MASK                                0xffffffff
   #define APERF1_BW2_ATWAIT_WIDTH                               32
   #define APERF1_BW2_ATWAIT_RESET                               0000000000
#define APERF1_BW2_AMAX                                          HW_REGISTER_RO( 0x7ee080cc ) 
   #define APERF1_BW2_AMAX_MASK                                  0x00ffffff
   #define APERF1_BW2_AMAX_WIDTH                                 24
   #define APERF1_BW2_AMAX_RESET                                 0000000000
#define APERF1_BW2_WTRANS                                        HW_REGISTER_RO( 0x7ee080d0 ) 
   #define APERF1_BW2_WTRANS_MASK                                0xffffffff
   #define APERF1_BW2_WTRANS_WIDTH                               32
   #define APERF1_BW2_WTRANS_RESET                               0000000000
#define APERF1_BW2_WTWAIT                                        HW_REGISTER_RO( 0x7ee080d4 ) 
   #define APERF1_BW2_WTWAIT_MASK                                0xffffffff
   #define APERF1_BW2_WTWAIT_WIDTH                               32
   #define APERF1_BW2_WTWAIT_RESET                               0000000000
#define APERF1_BW2_WMAX                                          HW_REGISTER_RO( 0x7ee080d8 ) 
   #define APERF1_BW2_WMAX_MASK                                  0x0ff0ffff
   #define APERF1_BW2_WMAX_WIDTH                                 28
   #define APERF1_BW2_WMAX_RESET                                 0000000000
#define APERF1_BW2_RTRANS                                        HW_REGISTER_RO( 0x7ee080dc ) 
   #define APERF1_BW2_RTRANS_MASK                                0xffffffff
   #define APERF1_BW2_RTRANS_WIDTH                               32
   #define APERF1_BW2_RTRANS_RESET                               0000000000
#define APERF1_BW2_RTWAIT                                        HW_REGISTER_RO( 0x7ee080e0 ) 
   #define APERF1_BW2_RTWAIT_MASK                                0xffffffff
   #define APERF1_BW2_RTWAIT_WIDTH                               32
   #define APERF1_BW2_RTWAIT_RESET                               0000000000
#define APERF1_BW2_RMAX                                          HW_REGISTER_RO( 0x7ee080e4 ) 
   #define APERF1_BW2_RMAX_MASK                                  0x00ffffff
   #define APERF1_BW2_RMAX_WIDTH                                 24
   #define APERF1_BW2_RMAX_RESET                                 0000000000
#define APERF1_BW2_RPEND                                         HW_REGISTER_RO( 0x7ee08068 ) 
   #define APERF1_BW2_RPEND_MASK                                 0x000000ff
   #define APERF1_BW2_RPEND_WIDTH                                8
   #define APERF1_BW2_RPEND_RESET                                0000000000
