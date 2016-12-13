/*
 * Copyright 2014, NICTA
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 *
 * @TAG(NICTA_BSD)
 */

//PMC event definitions
/* Note: there are lots of these. Only seemingly interesting ones -- that is,
 * either core sel4bench events, or ones closely related -- are included here.
 * Note2: events numbers are 32 bits long, and are divided into a cmask, flags
 * umask and event ID bytes (see intel software developer manual for details),
 * though most events will have cmask and flags equal to 0. Events with the same
 * cmask, flags and ID, but differing masks, can usually be ORed together, in
 * which case they'll be counted together.
 * The USR and OS flags are set in sel4bench_set_count_event() regardless of the
 * value in the event.
 */

//Arch
#define SEL4BENCH_IA32_EVENT_CYCLE_CORE          0x003C
#define SEL4BENCH_IA32_EVENT_CYCLE_BUS           0x013C
#define SEL4BENCH_IA32_EVENT_CACHE_LLC_ACCESS    0x4F2E
#define SEL4BENCH_IA32_EVENT_CACHE_LLC_MISS      0x412E
#define SEL4BENCH_IA32_EVENT_EXECUTE_INSTRUCTION 0x00C0
#define SEL4BENCH_IA32_EVENT_EXECUTE_BRANCH      0x00C4
#define SEL4BENCH_IA32_EVENT_BRANCH_MISPREDICT   0x00C5
//event modifiers
#define SEL4BENCH_IA32_MESI(X, EVENT)     ((EVENT) | ((X) <<  8))
#define SEL4BENCH_IA32_CORE(X, EVENT)     ((EVENT) | ((X) << 14))
#define SEL4BENCH_IA32_PREFETCH(X, EVENT) ((EVENT) | ((X) << 12))
#define SEL4BENCH_IA32_CORE_SELF          0x1
#define SEL4BENCH_IA32_CORE_ALL           0x3
#define SEL4BENCH_IA32_PREFETCH_NONE      0x0
#define SEL4BENCH_IA32_PREFETCH_ONLY      0x1
#define SEL4BENCH_IA32_PREFETCH_ALL       0x3
#define SEL4BENCH_IA32_M                  BIT(3)
#define SEL4BENCH_IA32_E                  BIT(2)
#define SEL4BENCH_IA32_S                  BIT(1)
#define SEL4BENCH_IA32_I                  BIT(0)
#define SEL4BENCH_IA32_CACHEMISS          SEL4BENCH_IA32_I
#define SEL4BENCH_IA32_CACHEHIT           (SEL4BENCH_IA32_M | SEL4BENCH_IA32_E | SEL4BENCH_IA32_S)

//Skylake uArch
#define SEL4BENCH_IA32_SKYLAKE_EVENT_LD_BLOCKS                      0xFF03
#define SEL4BENCH_IA32_SKYLAKE_EVENT_LD_BLOCKS_PARTIAL              0xFF07
#define SEL4BENCH_IA32_SKYLAKE_EVENT_DTLB_LOAD_MISSES               0xFF08
#define SEL4BENCH_IA32_SKYLAKE_EVENT_INT_MISC_RECOVERY_CYCLES       0x010D
#define SEL4BENCH_IA32_SKYLAKE_EVENT_INT_MISC_CLEAR_RESTEER_CYCLES  0x800D
#define SEL4BENCH_IA32_SKYLAKE_EVENT_UOPS_ISSUED_ANY                0x010E
#define SEL4BENCH_IA32_SKYLAKE_EVENT_UOPS_ISSUED_SLOW_LEA           0x200E
#define SEL4BENCH_IA32_SKYLAKE_EVENT_ARITH_FPU_DIV_ACTIVE           0x0114
#define SEL4BENCH_IA32_SKYLAKE_EVENT_L2_RQSTS                       0xFF24
#define SEL4BENCH_IA32_SKYLAKE_EVENT_L2_RQSTS_MISS                  0x3F24
#define SEL4BENCH_IA32_SKYLAKE_EVENT_DTLB_STORE_MISSES              0xFF49
#define SEL4BENCH_IA32_SKYLAKE_EVENT_L1D_REPLACEMENT                0x0151
#define SEL4BENCH_IA32_SKYLAKE_EVENT_RS_EVENTS_EMPTY_CYCLES         0x015E
#define SEL4BENCH_IA32_SKYLAKE_EVENT_LOCK_CYCLES                    0xFF63
#define SEL4BENCH_IA32_SKYLAKE_EVENT_IDQ_MITE_UOPS                  0x0479
#define SEL4BENCH_IA32_SKYLAKE_EVENT_IDQ_DSB_UOPS                   0x0879
#define SEL4BENCH_IA32_SKYLAKE_EVENT_IDQ_MS_UOPS                    0x3079
#define SEL4BENCH_IA32_SKYLAKE_EVENT_ICACHE_IFDATA_STALL            0x0480
#define SEL4BENCH_IA32_SKYLAKE_EVENT_ICACHE_64B_IFTAG_MISS          0x0283
#define SEL4BENCH_IA32_SKYLAKE_EVENT_ITLB_MISSES                    0xFF85
#define SEL4BENCH_IA32_SKYLAKE_EVENT_ILD_STALL                      0xFF87
#define SEL4BENCH_IA32_SKYLAKE_EVENT_IDQ_UOPS_NOT_DELIVERED_CORE    0x019C
#define SEL4BENCH_IA32_SKYLAKE_EVENT_UOPS_EXECUTED_PORT_0           0x01A1
#define SEL4BENCH_IA32_SKYLAKE_EVENT_UOPS_EXECUTED_PORT_1           0x02A1
#define SEL4BENCH_IA32_SKYLAKE_EVENT_UOPS_EXECUTED_PORT_2           0x04A1
#define SEL4BENCH_IA32_SKYLAKE_EVENT_UOPS_EXECUTED_PORT_3           0x08A1
#define SEL4BENCH_IA32_SKYLAKE_EVENT_UOPS_EXECUTED_PORT_4           0x10A1
#define SEL4BENCH_IA32_SKYLAKE_EVENT_UOPS_EXECUTED_PORT_5           0x20A1
#define SEL4BENCH_IA32_SKYLAKE_EVENT_UOPS_EXECUTED_PORT_6           0x40A1
#define SEL4BENCH_IA32_SKYLAKE_EVENT_UOPS_EXECUTED_PORT_7           0x80A1
#define SEL4BENCH_IA32_SKYLAKE_EVENT_RESOURCE_STALLS_ANY            0x01A2
#define SEL4BENCH_IA32_SKYLAKE_EVENT_RESOURCE_STALLS_SB             0x08A2
#define SEL4BENCH_IA32_SKYLAKE_EVENT_CYCLE_ACTIVITY_STALLS_TOTAL 0x040004A3
#define SEL4BENCH_IA32_SKYLAKE_EVENT_CYCLE_ACTIVITY_STALLS_L1D_MISS 0x0C000CA3
#define SEL4BENCH_IA32_SKYLAKE_EVENT_EXE_ACTIVITY_EXE_BOUND_0_PORTS 0x01A6
#define SEL4BENCH_IA32_SKYLAKE_EVENT_EXE_ACTIVITY_1_PORTS_UTIL      0x02A6
#define SEL4BENCH_IA32_SKYLAKE_EVENT_EXE_ACTIVITY_2_PORTS_UTIL      0x04A6
#define SEL4BENCH_IA32_SKYLAKE_EVENT_EXE_ACTIVITY_3_PORTS_UTIL      0x08A6
#define SEL4BENCH_IA32_SKYLAKE_EVENT_EXE_ACTIVITY_4_PORTS_UTIL      0x10A6
#define SEL4BENCH_IA32_SKYLAKE_EVENT_EXE_ACTIVITY_BOUND_ON_STORES   0x40A6
#define SEL4BENCH_IA32_SKYLAKE_EVENT_LSD_UOPS                       0x01A8
#define SEL4BENCH_IA32_SKYLAKE_EVENT_LSD_CYCLES_ACTIVE          0x010001A8
#define SEL4BENCH_IA32_SKYLAKE_EVENT_LSD_CYCLES_4_UOPS          0x040001A8
#define SEL4BENCH_IA32_SKYLAKE_EVENT_DSB2MITE_SWITCHES_PENALTY_CYCLES 0x02AB
#define SEL4BENCH_IA32_SKYLAKE_EVENT_OFFCORE_REQUESTS               0xFFB0
#define SEL4BENCH_IA32_SKYLAKE_EVENT_UOPS_EXECUTED_CORE             0x02B1
#define SEL4BENCH_IA32_SKYLAKE_EVENT_UOPS_EXECUTED_CORE_CYCLES_GE_1 0x010002B1
#define SEL4BENCH_IA32_SKYLAKE_EVENT_UOPS_EXECUTED_CORE_CYCLES_GE_2 0x020002B1
#define SEL4BENCH_IA32_SKYLAKE_EVENT_UOPS_EXECUTED_x87              0x10B1
#define SEL4BENCH_IA32_SKYLAKE_EVENT_UOPS_OTHERS_ASSISTS_ANY        0x3FC1
#define SEL4BENCH_IA32_SKYLAKE_EVENT_UOPS_RETIRED_ALL               0x01C2
#define SEL4BENCH_IA32_SKYLAKE_EVENT_UOPS_RETIRED_RETIRE_SLOTS      0x02C2
#define SEL4BENCH_IA32_SKYLAKE_EVENT_MACHINE_CLEARS                 0xFFC3
#define SEL4BENCH_IA32_SKYLAKE_EVENT_FP_ASSIST_ANY                  0xFFCA
#define SEL4BENCH_IA32_SKYLAKE_EVENT_HW_INTERRUPTS_RECEIVED         0x01CB

//Haswell uArch
#define SEL4BENCH_IA32_HASWELL_EVENT_LD_BLOCKS                      0xFF03
#define SEL4BENCH_IA32_HASWELL_EVENT_MISALIGN_MEM                   0xFF05
#define SEL4BENCH_IA32_HASWELL_EVENT_DTLB_LOAD_MISSES               0xFF08
#define SEL4BENCH_IA32_HASWELL_EVENT_INT_MISC_RECOVERY_CYCLES   0x0100030D
#define SEL4BENCH_IA32_HASWELL_EVENT_UOPS_ISSUED_ANY                0x010E
#define SEL4BENCH_IA32_HASWELL_EVENT_UOPS_ISSUED_FLAGS_MERGE        0x100E
#define SEL4BENCH_IA32_HASWELL_EVENT_UOPS_ISSUED_SLOW_LEA           0x200E
#define SEL4BENCH_IA32_HASWELL_EVENT_UOPS_ISSUED_SINGLE_MUL         0x400E
#define SEL4BENCH_IA32_HASWELL_EVENT_L2_RQSTS                       0xFF24
#define SEL4BENCH_IA32_HASWELL_EVENT_L2_RQSTS_MISS                  0x3F24
#define SEL4BENCH_IA32_HASWELL_EVENT_DTLB_STORE_MISSES              0xFF49
#define SEL4BENCH_IA32_HASWELL_EVENT_L1D_REPLACEMENT                0x0151
#define SEL4BENCH_IA32_HASWELL_EVENT_MOVE_ELIMINATION_INT_NOT_ELIMINATED 0x0458
#define SEL4BENCH_IA32_HASWELL_EVENT_MOVE_ELIMINATION_INT_ELIMINATED 0x0158
#define SEL4BENCH_IA32_HASWELL_EVENT_CPL_CYCLES_RING0               0x015C
#define SEL4BENCH_IA32_HASWELL_EVENT_CPL_CYCLES_RING123             0x025C
#define SEL4BENCH_IA32_HASWELL_EVENT_RS_EVENTS_EMPTY_CYCLES         0x015E
#define SEL4BENCH_IA32_HASWELL_EVENT_IDQ_EMPTY                      0x0279
#define SEL4BENCH_IA32_HASWELL_EVENT_IDQ_MITE_UOPS                  0x0479
#define SEL4BENCH_IA32_HASWELL_EVENT_IDQ_DSB_UOPS                   0x0879
#define SEL4BENCH_IA32_HASWELL_EVENT_IDQ_MS_UOPS                    0x3079
#define SEL4BENCH_IA32_HASWELL_EVENT_ICACHE_MISSES                  0x0280
#define SEL4BENCH_IA32_HASWELL_EVENT_ITLB_MISSES                    0xFF85
#define SEL4BENCH_IA32_HASWELL_EVENT_ILD_STALL                      0xFF87
#define SEL4BENCH_IA32_HASWELL_EVENT_IDQ_UOPS_NOT_DELIVERED_CORE    0x019C
#define SEL4BENCH_IA32_HASWELL_EVENT_UOPS_EXECUTED_PORT_0           0x01A1
#define SEL4BENCH_IA32_HASWELL_EVENT_UOPS_EXECUTED_PORT_1           0x02A1
#define SEL4BENCH_IA32_HASWELL_EVENT_UOPS_EXECUTED_PORT_2           0x04A1
#define SEL4BENCH_IA32_HASWELL_EVENT_UOPS_EXECUTED_PORT_3           0x08A1
#define SEL4BENCH_IA32_HASWELL_EVENT_UOPS_EXECUTED_PORT_4           0x10A1
#define SEL4BENCH_IA32_HASWELL_EVENT_UOPS_EXECUTED_PORT_5           0x20A1
#define SEL4BENCH_IA32_HASWELL_EVENT_UOPS_EXECUTED_PORT_6           0x40A1
#define SEL4BENCH_IA32_HASWELL_EVENT_UOPS_EXECUTED_PORT_7           0x80A1
#define SEL4BENCH_IA32_HASWELL_EVENT_RESOURCE_STALLS_ANY            0x01A2
#define SEL4BENCH_IA32_HASWELL_EVENT_RESOURCE_STALLS_RS             0x04A2
#define SEL4BENCH_IA32_HASWELL_EVENT_RESOURCE_STALLS_SB             0x08A2
#define SEL4BENCH_IA32_HASWELL_EVENT_RESOURCE_STALLS_ROB            0x10A2
#define SEL4BENCH_IA32_HASWELL_EVENT_CYCLE_ACTIVITY_CYCLES_LDM_PENDING 0x020002A3
#define SEL4BENCH_IA32_HASWELL_EVENT_CYCLE_ACTIVITY_CYCLES_NO_EXECUTE 0x040004A3
#define SEL4BENCH_IA32_HASWELL_EVENT_CYCLE_ACTIVITY_STALLS_LDM_PENDING 0x060005A3
#define SEL4BENCH_IA32_HASWELL_EVENT_CYCLE_ACTIVITY_STALLS_L1D_PENDING 0x0C000CA3 // PMC2 only
#define SEL4BENCH_IA32_HASWELL_EVENT_OFFCORE_REQUESTS               0xFFB0
#define SEL4BENCH_IA32_HASWELL_EVENT_UOPS_EXECUTED_CORE             0x02B1
#define SEL4BENCH_IA32_HASWELL_EVENT_UOPS_EXECUTED_CORE_1C      0x010002B1
#define SEL4BENCH_IA32_HASWELL_EVENT_UOPS_EXECUTED_CORE_2C      0x020002B1
#define SEL4BENCH_IA32_HASWELL_EVENT_UOPS_RETIRED_ALL               0x01C2
#define SEL4BENCH_IA32_HASWELL_EVENT_UOPS_RETIRED_RETIRE_SLOTS      0x02C2
#define SEL4BENCH_IA32_HASWELL_EVENT_MACHINE_CLEARS                 0xFFC3
#define SEL4BENCH_IA32_HASWELL_EVENT_FP_ASSIST_ANY                  0xFFCA
#define SEL4BENCH_IA32_HASWELL_EVENT_ROB_MISC_EVENTS_LBR_INSERTS    0x20CC
#define SEL4BENCH_IA32_HASWELL_EVENT_MEM_UOPS_RETIRED_ALL           0xFFD0
#define SEL4BENCH_IA32_HASWELL_EVENT_MEM_UOPS_RETIRED_ALL_LOADS     0xF1D0
#define SEL4BENCH_IA32_HASWELL_EVENT_MEM_UOPS_RETIRED_ALL_STORES    0xF2D0

#define SEL4BENCH_IA32_HASWELL_EVENT_TX_MEM_ABORT_CONFLICT          0x0154
#define SEL4BENCH_IA32_HASWELL_EVENT_TX_MEM_ABORT_CAPACITY_WRITE    0x0154
/* Counts the number of times a class of instructions that may cause a
   transactional abort was executed. Since this is the count of execution,
   it may not always cause a transactional abort. */
#define SEL4BENCH_IA32_HASWELL_EVENT_TX_EXEC_MISC1                  0x015D
/* Counts the number of times a class of instructions (e.g. vzeroupper) that
   may cause a transactional abort was executed inside a transactional region */
#define SEL4BENCH_IA32_HASWELL_EVENT_TX_EXEC_MISC2                  0x025D
#define SEL4BENCH_IA32_HASWELL_EVENT_TX_EXEC_NEST_EXCEEDED          0x045D
#define SEL4BENCH_IA32_HASWELL_EVENT_RTM_RETIRED_START              0x01C9
#define SEL4BENCH_IA32_HASWELL_EVENT_RTM_RETIRED_COMMIT             0x02C9
#define SEL4BENCH_IA32_HASWELL_EVENT_RTM_RETIRED_ABORTED            0x04C9
#define SEL4BENCH_IA32_HASWELL_EVENT_RTM_RETIRED_ABORTED_MEM_EVENT  0x08C9
#define SEL4BENCH_IA32_HASWELL_EVENT_RTM_RETIRED_ABORTED_RARE       0x10C9
#define SEL4BENCH_IA32_HASWELL_EVENT_RTM_RETIRED_ABORTED_HLE        0x20C9
#define SEL4BENCH_IA32_HASWELL_EVENT_RTM_RETIRED_ABORTED_MEM_TYPE   0x40C9
#define SEL4BENCH_IA32_HASWELL_EVENT_RTM_RETIRED_ABORTED_OTHER      0x80C9

//Sandy Bridge uArch
#define SEL4BENCH_IA32_SANDYBRIDGE_EVENT_LD_BLOCKS                      0xFF03
#define SEL4BENCH_IA32_SANDYBRIDGE_EVENT_MISALIGN_MEM                   0xFF05
#define SEL4BENCH_IA32_SANDYBRIDGE_EVENT_LD_BLOCKS_PARTIAL              0xFF07
#define SEL4BENCH_IA32_SANDYBRIDGE_EVENT_DTLB_LOAD_MISSES               0xFF08
#define SEL4BENCH_IA32_SANDYBRIDGE_EVENT_INT_MISC_RECOVERY_CYCLES   0x0100030D
#define SEL4BENCH_IA32_SANDYBRIDGE_EVENT_UOPS_ISSUED_ANY                0x010E
#define SEL4BENCH_IA32_SANDYBRIDGE_EVENT_FP_COMP_OPS_EXE                0xFF10
#define SEL4BENCH_IA32_SANDYBRIDGE_EVENT_SIMP_FP_256                    0xFF11
#define SEL4BENCH_IA32_SANDYBRIDGE_EVENT_ARITH_FPU_DIV_ACTIVE           0x0114
#define SEL4BENCH_IA32_SANDYBRIDGE_EVENT_L2_RQSTS                       0xFF24
#define SEL4BENCH_IA32_SANDYBRIDGE_EVENT_L1_L1D_WB_RQSTS_ALL            0xFF28
#define SEL4BENCH_IA32_SANDYBRIDGE_EVENT_DTLB_STORE_MISSES              0xFF49
#define SEL4BENCH_IA32_SANDYBRIDGE_EVENT_L1D_REPLACEMENT                0x0151
#define SEL4BENCH_IA32_SANDYBRIDGE_EVENT_RESOURCE_STALLS2_ALL_FL_EMPTY  0x0C5B
#define SEL4BENCH_IA32_SANDYBRIDGE_EVENT_RESOURCE_STALLS2_ALL_PRF_CONTROL 0x0F5B
#define SEL4BENCH_IA32_SANDYBRIDGE_EVENT_RESOURCE_STALLS2_BOB_FULL      0x405B
#define SEL4BENCH_IA32_SANDYBRIDGE_EVENT_CPL_CYCLES_RING0               0x015C
#define SEL4BENCH_IA32_SANDYBRIDGE_EVENT_CPL_CYCLES_RING123             0x025C
#define SEL4BENCH_IA32_SANDYBRIDGE_EVENT_RS_EVENTS_EMPTY_CYCLES         0x015E
#define SEL4BENCH_IA32_SANDYBRIDGE_EVENT_LOCK_CYCLES                    0xFF63
#define SEL4BENCH_IA32_SANDYBRIDGE_EVENT_IDQ_EMPTY                      0x0279
#define SEL4BENCH_IA32_SANDYBRIDGE_EVENT_IDQ_MITE_UOPS                  0x0479
#define SEL4BENCH_IA32_SANDYBRIDGE_EVENT_IDQ_DSB_UOPS                   0x0879
#define SEL4BENCH_IA32_SANDYBRIDGE_EVENT_IDQ_MS_UOPS                    0x3079
#define SEL4BENCH_IA32_SANDYBRIDGE_EVENT_ICACHE_MISSES                  0x0280
#define SEL4BENCH_IA32_SANDYBRIDGE_EVENT_ITLB_MISSES                    0xFF85
#define SEL4BENCH_IA32_SANDYBRIDGE_EVENT_ILD_STALL                      0xFF87
#define SEL4BENCH_IA32_SANDYBRIDGE_EVENT_IDQ_UOPS_NOT_DELIVERED_CORE    0x019C
#define SEL4BENCH_IA32_SANDYBRIDGE_EVENT_UOPS_DISPATCHED_PORT_0         0x01A1
#define SEL4BENCH_IA32_SANDYBRIDGE_EVENT_UOPS_DISPATCHED_PORT_1         0x02A1
#define SEL4BENCH_IA32_SANDYBRIDGE_EVENT_UOPS_DISPATCHED_PORT_2         0x0CA1
#define SEL4BENCH_IA32_SANDYBRIDGE_EVENT_UOPS_DISPATCHED_PORT_3         0x30A1
#define SEL4BENCH_IA32_SANDYBRIDGE_EVENT_UOPS_DISPATCHED_PORT_4         0x40A1
#define SEL4BENCH_IA32_SANDYBRIDGE_EVENT_UOPS_DISPATCHED_PORT_5         0x80A1
#define SEL4BENCH_IA32_SANDYBRIDGE_EVENT_RESOURCE_STALLS_ANY            0x01A2
#define SEL4BENCH_IA32_SANDYBRIDGE_EVENT_RESOURCE_STALLS_LB             0x02A2
#define SEL4BENCH_IA32_SANDYBRIDGE_EVENT_RESOURCE_STALLS_RS             0x04A2
#define SEL4BENCH_IA32_SANDYBRIDGE_EVENT_RESOURCE_STALLS_SB             0x08A2
#define SEL4BENCH_IA32_SANDYBRIDGE_EVENT_RESOURCE_STALLS_ROB            0x10A2
#define SEL4BENCH_IA32_SANDYBRIDGE_EVENT_RESOURCE_STALLS_FCSW           0x20A2
#define SEL4BENCH_IA32_SANDYBRIDGE_EVENT_OFFCORE_REQUESTS               0xFFB0
#define SEL4BENCH_IA32_SANDYBRIDGE_EVENT_UOPS_DISPATCHED_THREAD         0x01B1
#define SEL4BENCH_IA32_SANDYBRIDGE_EVENT_UOPS_DISPATCHED_CORE           0x02B1
#define SEL4BENCH_IA32_SANDYBRIDGE_EVENT_AGU_BYPASS_CANCEL_COUNT        0x01B6
#define SEL4BENCH_IA32_SANDYBRIDGE_EVENT_TLB_FLUSH                      0xFFBD
#define SEL4BENCH_IA32_SANDYBRIDGE_EVENT_L1D_BLOCKS_BANK_CONFLICT_CYCLES 0x05BF
#define SEL4BENCH_IA32_SANDYBRIDGE_EVENT_UOPS_RETIRED_ALL               0x01C2
#define SEL4BENCH_IA32_SANDYBRIDGE_EVENT_UOPS_RETIRED_RETIRE_SLOTS      0x02C2
#define SEL4BENCH_IA32_SANDYBRIDGE_EVENT_MACHINE_CLEARS                 0xFFC3
#define SEL4BENCH_IA32_SANDYBRIDGE_EVENT_FP_ASSIST_ANY                  0xFFCA
#define SEL4BENCH_IA32_SANDYBRIDGE_EVENT_ROB_MISC_EVENTS_LBR_INSERTS    0x20CC
#define SEL4BENCH_IA32_SANDYBRIDGE_EVENT_MEM_UOPS_RETIRED_ALL           0xFFD0
#define SEL4BENCH_IA32_SANDYBRIDGE_EVENT_MEM_UOPS_RETIRED_ALL_LOADS     0xF1D0
#define SEL4BENCH_IA32_SANDYBRIDGE_EVENT_MEM_UOPS_RETIRED_ALL_STORES    0xF2D0

//Westmere uArch
#define SEL4BENCH_IA32_WESTMERE_EVENT_TLB_DMISS_READ       0x0208
#define SEL4BENCH_IA32_WESTMERE_EVENT_TLB_DHIT_READ        0x1008
#define SEL4BENCH_IA32_WESTMERE_EVENT_CACHE_L2_READ_HIT    0x0124
#define SEL4BENCH_IA32_WESTMERE_EVENT_CACHE_L2_READ_MISS   0x0224
#define SEL4BENCH_IA32_WESTMERE_EVENT_CACHE_L2_WRITE_HIT   0x0424
#define SEL4BENCH_IA32_WESTMERE_EVENT_CACHE_L2_WRITE_MISS  0x0824
#define SEL4BENCH_IA32_WESTMERE_EVENT_CACHE_L2_IFETCH_HIT  0x1024
#define SEL4BENCH_IA32_WESTMERE_EVENT_CACHE_L2_IFETCH_MISS 0x2024
#define SEL4BENCH_IA32_WESTMERE_EVENT_CACHE_L2_PFETCH_HIT  0x4024
#define SEL4BENCH_IA32_WESTMERE_EVENT_CACHE_L2_PFETCH_MISS 0x8024
#define SEL4BENCH_IA32_WESTMERE_EVENT_CACHE_L2_ACCESS      0x0026 //modifiers: MESI (demand), MESI << 4 (prefetch)
#define SEL4BENCH_IA32_WESTMERE_EVENT_CACHE_L2_WRITE       0x0027 //modifiers: MESI (   RFO), MESI << 4 (    lock)
#define SEL4BENCH_IA32_WESTMERE_EVENT_CACHE_L3_MISS        0x012E
#define SEL4BENCH_IA32_WESTMERE_EVENT_CACHE_L3_ACCESS      0x022E
#define SEL4BENCH_IA32_WESTMERE_EVENT_TLB_DMISS            0x0249
#define SEL4BENCH_IA32_WESTMERE_EVENT_CACHE_L1D_LINES_IN   0x0151 //must use counter 0 or 1
#define SEL4BENCH_IA32_WESTMERE_EVENT_CACHE_L1I_HIT        0x0180
#define SEL4BENCH_IA32_WESTMERE_EVENT_CACHE_L1I_MISS       0x0280
#define SEL4BENCH_IA32_WESTMERE_EVENT_TLB_IHIT_LARGEPAGE   0x0182
#define SEL4BENCH_IA32_WESTMERE_EVENT_TLB_IMISS            0x0285
#define SEL4BENCH_IA32_WESTMERE_EVENT_EXECUTE_BRANCH       0x7F88
#define SEL4BENCH_IA32_WESTMERE_EVENT_BRANCH_MISPREDICT    0x7F89
#define SEL4BENCH_IA32_WESTMERE_EVENT_TLB_IFLUSH           0x01AE
#define SEL4BENCH_IA32_WESTMERE_EVENT_RETIRE_INSTRUCTION   0x00C0
#define SEL4BENCH_IA32_WESTMERE_EVENT_SELF_MODIFYING_CODE  0x04C3
#define SEL4BENCH_IA32_WESTMERE_EVENT_RETIRE_BRANCH        0x00C4
#define SEL4BENCH_IA32_WESTMERE_EVENT_BRANCH_MISPREDICT_R  0x00C5
#define SEL4BENCH_IA32_WESTMERE_EVENT_TLB_IMISS_R          0x20C8
#define SEL4BENCH_IA32_WESTMERE_EVENT_CACHE_L1D_HIT_R      0x01CB
#define SEL4BENCH_IA32_WESTMERE_EVENT_CACHE_L2_HIT_R       0x02CB
#define SEL4BENCH_IA32_WESTMERE_EVENT_CACHE_L3P_HIT_R      0x04CB
#define SEL4BENCH_IA32_WESTMERE_EVENT_CACHE_L3_HIT_R       0x08CB
#define SEL4BENCH_IA32_WESTMERE_EVENT_CACHE_L3_MISS_R      0x10CB
#define SEL4BENCH_IA32_WESTMERE_EVENT_CACHE_LFB_HIT_R      0x40CB
#define SEL4BENCH_IA32_WESTMERE_EVENT_TLB_DMISS_R          0x80CB

//Nehalem uArch
#define SEL4BENCH_IA32_NEHALEM_EVENT_TLB_DMISS_READ       0x0208
#define SEL4BENCH_IA32_NEHALEM_EVENT_TLB_DHIT_READ        0x1008
#define SEL4BENCH_IA32_NEHALEM_EVENT_CACHE_L2_READ_HIT    0x0124
#define SEL4BENCH_IA32_NEHALEM_EVENT_CACHE_L2_READ_MISS   0x0224
#define SEL4BENCH_IA32_NEHALEM_EVENT_CACHE_L2_WRITE_HIT   0x0424
#define SEL4BENCH_IA32_NEHALEM_EVENT_CACHE_L2_WRITE_MISS  0x0824
#define SEL4BENCH_IA32_NEHALEM_EVENT_CACHE_L2_IFETCH_HIT  0x1024
#define SEL4BENCH_IA32_NEHALEM_EVENT_CACHE_L2_IFETCH_MISS 0x2024
#define SEL4BENCH_IA32_NEHALEM_EVENT_CACHE_L2_PFETCH_HIT  0x4024
#define SEL4BENCH_IA32_NEHALEM_EVENT_CACHE_L2_PFETCH_MISS 0x8024
#define SEL4BENCH_IA32_NEHALEM_EVENT_CACHE_L2_ACCESS      0x0026 //modifiers: MESI (demand), MESI << 4 (prefetch)
#define SEL4BENCH_IA32_NEHALEM_EVENT_CACHE_L2_WRITE       0x0027 //modifiers: MESI (   RFO), MESI << 4 (    lock)
#define SEL4BENCH_IA32_NEHALEM_EVENT_CACHE_L3_MISS        0x412E
#define SEL4BENCH_IA32_NEHALEM_EVENT_CACHE_L3_ACCESS      0x4F2E
#define SEL4BENCH_IA32_NEHALEM_EVENT_CACHE_L1D_READ       0x0040 //modifiers: MESI; must use counter 0 or 1
#define SEL4BENCH_IA32_NEHALEM_EVENT_CACHE_L1D_WRITE      0x0041 //modifiers: MESI; must use counter 0 or 1
#define SEL4BENCH_IA32_NEHALEM_EVENT_CACHE_L1D_READ_LOCK  0x0042 //modifiers: MESI; must use counter 0 or 1
#define SEL4BENCH_IA32_NEHALEM_EVENT_CACHE_L1D_ACCESS     0x0143 //must use counter 0 or 1
#define SEL4BENCH_IA32_NEHALEM_EVENT_CACHE_L1D_ACCESS_C   0x0243 //must use counter 0 or 1
#define SEL4BENCH_IA32_NEHALEM_EVENT_TLB_DMISS            0x0249
#define SEL4BENCH_IA32_NEHALEM_EVENT_CACHE_L1D_LINES_IN   0x0151 //must use counter 0 or 1
#define SEL4BENCH_IA32_NEHALEM_EVENT_CACHE_L1I_HIT        0x0180
#define SEL4BENCH_IA32_NEHALEM_EVENT_CACHE_L1I_MISS       0x0280
#define SEL4BENCH_IA32_NEHALEM_EVENT_TLB_IHIT_LARGEPAGE   0x0182
#define SEL4BENCH_IA32_NEHALEM_EVENT_TLB_IMISS            0x0285
#define SEL4BENCH_IA32_NEHALEM_EVENT_EXECUTE_BRANCH       0x7F88
#define SEL4BENCH_IA32_NEHALEM_EVENT_BRANCH_MISPREDICT    0x7F89
#define SEL4BENCH_IA32_NEHALEM_EVENT_TLB_IFLUSH           0x01AE
#define SEL4BENCH_IA32_NEHALEM_EVENT_RETIRE_INSTRUCTION   0x00C0
#define SEL4BENCH_IA32_NEHALEM_EVENT_SELF_MODIFYING_CODE  0x04C3
#define SEL4BENCH_IA32_NEHALEM_EVENT_RETIRE_BRANCH        0x00C4
#define SEL4BENCH_IA32_NEHALEM_EVENT_BRANCH_MISPREDICT_R  0x00C5
#define SEL4BENCH_IA32_NEHALEM_EVENT_TLB_IMISS_R          0x20C8
#define SEL4BENCH_IA32_NEHALEM_EVENT_CACHE_L1D_HIT_R      0x01CB
#define SEL4BENCH_IA32_NEHALEM_EVENT_CACHE_L2_HIT_R       0x02CB
#define SEL4BENCH_IA32_NEHALEM_EVENT_CACHE_L3P_HIT_R      0x04CB
#define SEL4BENCH_IA32_NEHALEM_EVENT_CACHE_L3_HIT_R       0x08CB
#define SEL4BENCH_IA32_NEHALEM_EVENT_CACHE_L3_MISS_R      0x10CB
#define SEL4BENCH_IA32_NEHALEM_EVENT_CACHE_LFB_HIT_R      0x40CB
#define SEL4BENCH_IA32_NEHALEM_EVENT_TLB_DMISS_R          0x80CB

//Core2 series (aka Core uArch)
//events are subject to modifiers above, as commented
#define SEL4BENCH_IA32_CORE2_EVENT_SEGMENT_LOAD         0x0006
#define SEL4BENCH_IA32_CORE2_EVENT_TLB_DMISS            0x0108
#define SEL4BENCH_IA32_CORE2_EVENT_TLB_DMISS_READ       0x0208
#define SEL4BENCH_IA32_CORE2_EVENT_TLB_L0D_MISS_READ    0x0408
#define SEL4BENCH_IA32_CORE2_EVENT_TLB_DMISS_WRITE      0x0808
#define SEL4BENCH_IA32_CORE2_EVENT_PAGETABLE_WALK       0x010C
#define SEL4BENCH_IA32_CORE2_EVENT_CACHE_L2_MISS        0x0024 //modifiers: CORE, PREFETCH
#define SEL4BENCH_IA32_CORE2_EVENT_CACHE_L2_EVICT       0x0026 //modifiers: CORE, PREFETCH
#define SEL4BENCH_IA32_CORE2_EVENT_CACHE_L2_IFETCH      0x0028 //modifiers: CORE, MESI
#define SEL4BENCH_IA32_CORE2_EVENT_CACHE_L2_READ        0x0029 //modifiers: CORE, PREFETCH, MESI
#define SEL4BENCH_IA32_CORE2_EVENT_CACHE_L2_WRITE       0x002A //modifiers: CORE, MESI
#define SEL4BENCH_IA32_CORE2_EVENT_CACHE_L2_LOCK        0x002B //modifiers: CORE, MESI
#define SEL4BENCH_IA32_CORE2_EVENT_CACHE_L2_ACCESS      0x002E //modifiers: CORE, PREFETCH, MESI
#define SEL4BENCH_IA32_CORE2_EVENT_CACHE_L1D_READ       0x0040 //modifiers: MESI
#define SEL4BENCH_IA32_CORE2_EVENT_CACHE_L1D_WRITE      0x0041 //modifiers: MESI
#define SEL4BENCH_IA32_CORE2_EVENT_CACHE_L1D_READ_LOCK  0x0042 //modifiers: MESI
#define SEL4BENCH_IA32_CORE2_EVENT_CACHE_L1D_ACCESS     0x0143
#define SEL4BENCH_IA32_CORE2_EVENT_CACHE_L1D_ACCESS_C   0x0243
#define SEL4BENCH_IA32_CORE2_EVENT_CACHE_L1D_READ_SPLIT 0x0149
#define SEL4BENCH_IA32_CORE2_EVENT_CACHE_L1D_WRITE_SPLIT 0x0249
#define SEL4BENCH_IA32_CORE2_EVENT_INSTRUCTION_FETCH    0x0080
#define SEL4BENCH_IA32_CORE2_EVENT_CACHE_L1I_MISS       0x0081
#define SEL4BENCH_IA32_CORE2_EVENT_TLB_IMISS_SMALLPAGE  0x0282
#define SEL4BENCH_IA32_CORE2_EVENT_TLB_IMISS_LARGEPAGE  0x1082
#define SEL4BENCH_IA32_CORE2_EVENT_TLB_IFLUSH           0x4082
#define SEL4BENCH_IA32_CORE2_EVENT_TLB_IMISS            0x1282
#define SEL4BENCH_IA32_CORE2_EVENT_EXECUTE_BRANCH       0x0088
#define SEL4BENCH_IA32_CORE2_EVENT_BRANCH_MISPREDICT    0x0089
#define SEL4BENCH_IA32_CORE2_EVENT_RETIRE_INSTRUCTION   0x00C0
#define SEL4BENCH_IA32_CORE2_EVENT_RETIRE_MEMORY_READ   0x01C0
#define SEL4BENCH_IA32_CORE2_EVENT_RETIRE_MEMORY_WRITE  0x02C0
#define SEL4BENCH_IA32_CORE2_EVENT_RETIRE_NONMEMORY     0x04C0
#define SEL4BENCH_IA32_CORE2_EVENT_SELF_MODIFYING_CODE  0x01C3
#define SEL4BENCH_IA32_CORE2_EVENT_RETIRE_BRANCH        0x00C4
#define SEL4BENCH_IA32_CORE2_EVENT_BRANCH_MISPREDICT_R  0x00C5
#define SEL4BENCH_IA32_CORE2_EVENT_HARDWARE_INTERRUPT   0x00C8
#define SEL4BENCH_IA32_CORE2_EVENT_TLB_IMISS_R          0x00C9
#define SEL4BENCH_IA32_CORE2_EVENT_CACHE_L1D_MISS_R     0x01CB //must use counter 0
#define SEL4BENCH_IA32_CORE2_EVENT_CACHE_L1D_MISS_LINE_R 0x02CB //must use counter 0
#define SEL4BENCH_IA32_CORE2_EVENT_CACHE_L2_MISS_R      0x04CB //must use counter 0
#define SEL4BENCH_IA32_CORE2_EVENT_CACHE_L2_MISS_LINE_R 0x08CB //must use counter 0
#define SEL4BENCH_IA32_CORE2_EVENT_TLB_DMISS_R          0x10CB //must use counter 0

//Core Solo / Core Duo processors
//events are subject to modifiers above, as commented
#define SEL4BENCH_IA32_CORE_EVENT_SEGMENT_LOAD         0x0006
#define SEL4BENCH_IA32_CORE_EVENT_CACHE_L2_ALLOC       0x0024
#define SEL4BENCH_IA32_CORE_EVENT_CACHE_L2_ALLOC_DIRTY 0x0025
#define SEL4BENCH_IA32_CORE_EVENT_CACHE_L2_EVICT       0x0026
#define SEL4BENCH_IA32_CORE_EVENT_CACHE_L2_EVICT_DIRTY 0x0027
#define SEL4BENCH_IA32_CORE_EVENT_CACHE_L2_IFETCH      0x0028 //modifiers: MESI
#define SEL4BENCH_IA32_CORE_EVENT_CACHE_L2_READ        0x0029 //modifiers: MESI
#define SEL4BENCH_IA32_CORE_EVENT_CACHE_L2_WRITE       0x002A //modifiers: MESI
#define SEL4BENCH_IA32_CORE_EVENT_CACHE_L2_ACCESS      0x002E //modifiers: MESI
#define SEL4BENCH_IA32_CORE_EVENT_CACHE_L1D_READ       0x0040 //modifiers: MESI
#define SEL4BENCH_IA32_CORE_EVENT_CACHE_L1D_WRITE      0x0041 //modifiers: MESI
#define SEL4BENCH_IA32_CORE_EVENT_CACHE_L1D_READ_LOCK  0x0042 //modifiers: MESI
#define SEL4BENCH_IA32_CORE_EVENT_CACHE_L1D_ACCESS     0x0143
#define SEL4BENCH_IA32_CORE_EVENT_CACHE_L1D_ACCESS_C   0x0243
#define SEL4BENCH_IA32_CORE_EVENT_CACHED_MEMORY_ACCESS 0x0244
#define SEL4BENCH_IA32_CORE_EVENT_CACHE_L1D_EVICT      0x0F45
#define SEL4BENCH_IA32_CORE_EVENT_CACHE_L1D_ALLOC_DIRTY 0x0046
#define SEL4BENCH_IA32_CORE_EVENT_CACHE_L1D_EVICT_DIRTY 0x0047
#define SEL4BENCH_IA32_CORE_EVENT_TLB_DMISS            0x0049
#define SEL4BENCH_IA32_CORE_EVENT_INSTRUCTION_FETCH    0x0080
#define SEL4BENCH_IA32_CORE_EVENT_CACHE_L1I_MISS       0x0081
#define SEL4BENCH_IA32_CORE_EVENT_TLB_IMISS            0x0085
#define SEL4BENCH_IA32_CORE_EVENT_EXECUTE_BRANCH       0x0088
#define SEL4BENCH_IA32_CORE_EVENT_BRANCH_MISPREDICT    0x0089
#define SEL4BENCH_IA32_CORE_EVENT_RETIRE_INSTRUCTION   0x00C0
#define SEL4BENCH_IA32_CORE_EVENT_SELF_MODIFYING_CODE  0x00C3
#define SEL4BENCH_IA32_CORE_EVENT_RETIRE_BRANCH        0x00C4
#define SEL4BENCH_IA32_CORE_EVENT_BRANCH_MISPREDICT_R  0x00C5
#define SEL4BENCH_IA32_CORE_EVENT_HARDWARE_INTERRUPT   0x00C8
#define SEL4BENCH_IA32_CORE_EVENT_RETIRE_BRANCH_TRUE   0x00C9
#define SEL4BENCH_IA32_CORE_EVENT_BRANCH_MISPREDICT_TRUE_R 0x00C5
#define SEL4BENCH_IA32_CORE_EVENT_BTB_MISS             0x00E2


//P6 family (PM, P3)
//new (or modified) in PM -- note, branch prediction events include speculative execution
#define SEL4BENCH_IA32_P6_EVENT_EXECUTE_BRANCH         0x0088
#define SEL4BENCH_IA32_P6_EVENT_BRANCH_MISPREDICT      0x0089
//all P6 processors
#define SEL4BENCH_IA32_P6_EVENT_CACHE_L2_LINES_IN      0x0024 //modifiers: PREFETCH, MESI
#define SEL4BENCH_IA32_P6_EVENT_CACHE_L2_IFETCH        0x0028 //modifiers: MESI
#define SEL4BENCH_IA32_P6_EVENT_CACHE_L2_READ          0x0029 //modifiers: PREFETCH, MESI
#define SEL4BENCH_IA32_P6_EVENT_CACHE_L2_WRITE         0x002A //modifiers: MESI
#define SEL4BENCH_IA32_P6_EVENT_MAIN_MEMORY_ACCESS     0x0043
#define SEL4BENCH_IA32_P6_EVENT_CACHE_L1D_LINES_IN     0x0045
#define SEL4BENCH_IA32_P6_EVENT_INSTRUCTION_FETCH      0x0080
#define SEL4BENCH_IA32_P6_EVENT_CACHE_L1I_MISS         0x0081
#define SEL4BENCH_IA32_P6_EVENT_TLB_IMISS              0x0085
#define SEL4BENCH_IA32_P6_EVENT_RETIRE_INSTRUCTION     0x00C0
#define SEL4BENCH_IA32_P6_EVENT_RETIRE_BRANCH          0x00C4
#define SEL4BENCH_IA32_P6_EVENT_BRANCH_MISPREDICT_R    0x00C5
#define SEL4BENCH_IA32_P6_EVENT_HARDWARE_INTERRUPT     0x00C8
#define SEL4BENCH_IA32_P6_EVENT_BTB_MISS               0x00E2

//generification layer
#define SEL4BENCH_IA32_EVENT_GENERIC_MASK            0xFFFF0000
enum {
	SEL4BENCH_IA32_EVENT_CACHE_L1I_MISS = 0 | SEL4BENCH_IA32_EVENT_GENERIC_MASK,
	SEL4BENCH_IA32_EVENT_CACHE_L1D_MISS = 1 | SEL4BENCH_IA32_EVENT_GENERIC_MASK,
	SEL4BENCH_IA32_EVENT_TLB_L1I_MISS = 2 | SEL4BENCH_IA32_EVENT_GENERIC_MASK,
	SEL4BENCH_IA32_EVENT_TLB_L1D_MISS = 3 | SEL4BENCH_IA32_EVENT_GENERIC_MASK,
	SEL4BENCH_IA32_EVENT_MEMORY_ACCESS = 4 | SEL4BENCH_IA32_EVENT_GENERIC_MASK
};
#define SEL4BENCH_IA32_EVENT_BRANCH_MISPREDICT       0x00C5
#define SEL4BENCH_IA32_EVENT_EXECUTE_INSTRUCTION     0x00C0

