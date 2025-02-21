#include "qemu/osdep.h"
#include "exec/gdbstub.h"

const GDBFeature gdb_static_features[] = {
    {
        "riscv-32bit-cpu.xml",
        "<?xml version=\"1.0\"?>\n"
        "<!-- Copyright (C) 2018-2019 Free Software Foundation, Inc.\n"
        "\n"
        "     Copying and distribution of this file, with or without modification,\n"
        "     are permitted in any medium without royalty provided the copyright\n"
        "     notice and this notice are preserved.  -->\n"
        "\n"
        "<!DOCTYPE feature SYSTEM \"gdb-target.dtd\">\n"
        "<feature name=\"org.gnu.gdb.riscv.cpu\">\n"
        "  <reg name=\"zero\" bitsize=\"32\" type=\"int\"/>\n"
        "  <reg name=\"ra\" bitsize=\"32\" type=\"code_ptr\"/>\n"
        "  <reg name=\"sp\" bitsize=\"32\" type=\"data_ptr\"/>\n"
        "  <reg name=\"gp\" bitsize=\"32\" type=\"data_ptr\"/>\n"
        "  <reg name=\"tp\" bitsize=\"32\" type=\"data_ptr\"/>\n"
        "  <reg name=\"t0\" bitsize=\"32\" type=\"int\"/>\n"
        "  <reg name=\"t1\" bitsize=\"32\" type=\"int\"/>\n"
        "  <reg name=\"t2\" bitsize=\"32\" type=\"int\"/>\n"
        "  <reg name=\"fp\" bitsize=\"32\" type=\"data_ptr\"/>\n"
        "  <reg name=\"s1\" bitsize=\"32\" type=\"int\"/>\n"
        "  <reg name=\"a0\" bitsize=\"32\" type=\"int\"/>\n"
        "  <reg name=\"a1\" bitsize=\"32\" type=\"int\"/>\n"
        "  <reg name=\"a2\" bitsize=\"32\" type=\"int\"/>\n"
        "  <reg name=\"a3\" bitsize=\"32\" type=\"int\"/>\n"
        "  <reg name=\"a4\" bitsize=\"32\" type=\"int\"/>\n"
        "  <reg name=\"a5\" bitsize=\"32\" type=\"int\"/>\n"
        "  <reg name=\"a6\" bitsize=\"32\" type=\"int\"/>\n"
        "  <reg name=\"a7\" bitsize=\"32\" type=\"int\"/>\n"
        "  <reg name=\"s2\" bitsize=\"32\" type=\"int\"/>\n"
        "  <reg name=\"s3\" bitsize=\"32\" type=\"int\"/>\n"
        "  <reg name=\"s4\" bitsize=\"32\" type=\"int\"/>\n"
        "  <reg name=\"s5\" bitsize=\"32\" type=\"int\"/>\n"
        "  <reg name=\"s6\" bitsize=\"32\" type=\"int\"/>\n"
        "  <reg name=\"s7\" bitsize=\"32\" type=\"int\"/>\n"
        "  <reg name=\"s8\" bitsize=\"32\" type=\"int\"/>\n"
        "  <reg name=\"s9\" bitsize=\"32\" type=\"int\"/>\n"
        "  <reg name=\"s10\" bitsize=\"32\" type=\"int\"/>\n"
        "  <reg name=\"s11\" bitsize=\"32\" type=\"int\"/>\n"
        "  <reg name=\"t3\" bitsize=\"32\" type=\"int\"/>\n"
        "  <reg name=\"t4\" bitsize=\"32\" type=\"int\"/>\n"
        "  <reg name=\"t5\" bitsize=\"32\" type=\"int\"/>\n"
        "  <reg name=\"t6\" bitsize=\"32\" type=\"int\"/>\n"
        "  <reg name=\"pc\" bitsize=\"32\" type=\"code_ptr\"/>\n"
        "</feature>\n",
        33,
    },
    {
        "riscv-32bit-fpu.xml",
        "<?xml version=\"1.0\"?>\n"
        "<!-- Copyright (C) 2018-2019 Free Software Foundation, Inc.\n"
        "\n"
        "     Copying and distribution of this file, with or without modification,\n"
        "     are permitted in any medium without royalty provided the copyright\n"
        "     notice and this notice are preserved.  -->\n"
        "\n"
        "<!DOCTYPE feature SYSTEM \"gdb-target.dtd\">\n"
        "<feature name=\"org.gnu.gdb.riscv.fpu\">\n"
        "  <reg name=\"ft0\" bitsize=\"32\" type=\"ieee_single\"/>\n"
        "  <reg name=\"ft1\" bitsize=\"32\" type=\"ieee_single\"/>\n"
        "  <reg name=\"ft2\" bitsize=\"32\" type=\"ieee_single\"/>\n"
        "  <reg name=\"ft3\" bitsize=\"32\" type=\"ieee_single\"/>\n"
        "  <reg name=\"ft4\" bitsize=\"32\" type=\"ieee_single\"/>\n"
        "  <reg name=\"ft5\" bitsize=\"32\" type=\"ieee_single\"/>\n"
        "  <reg name=\"ft6\" bitsize=\"32\" type=\"ieee_single\"/>\n"
        "  <reg name=\"ft7\" bitsize=\"32\" type=\"ieee_single\"/>\n"
        "  <reg name=\"fs0\" bitsize=\"32\" type=\"ieee_single\"/>\n"
        "  <reg name=\"fs1\" bitsize=\"32\" type=\"ieee_single\"/>\n"
        "  <reg name=\"fa0\" bitsize=\"32\" type=\"ieee_single\"/>\n"
        "  <reg name=\"fa1\" bitsize=\"32\" type=\"ieee_single\"/>\n"
        "  <reg name=\"fa2\" bitsize=\"32\" type=\"ieee_single\"/>\n"
        "  <reg name=\"fa3\" bitsize=\"32\" type=\"ieee_single\"/>\n"
        "  <reg name=\"fa4\" bitsize=\"32\" type=\"ieee_single\"/>\n"
        "  <reg name=\"fa5\" bitsize=\"32\" type=\"ieee_single\"/>\n"
        "  <reg name=\"fa6\" bitsize=\"32\" type=\"ieee_single\"/>\n"
        "  <reg name=\"fa7\" bitsize=\"32\" type=\"ieee_single\"/>\n"
        "  <reg name=\"fs2\" bitsize=\"32\" type=\"ieee_single\"/>\n"
        "  <reg name=\"fs3\" bitsize=\"32\" type=\"ieee_single\"/>\n"
        "  <reg name=\"fs4\" bitsize=\"32\" type=\"ieee_single\"/>\n"
        "  <reg name=\"fs5\" bitsize=\"32\" type=\"ieee_single\"/>\n"
        "  <reg name=\"fs6\" bitsize=\"32\" type=\"ieee_single\"/>\n"
        "  <reg name=\"fs7\" bitsize=\"32\" type=\"ieee_single\"/>\n"
        "  <reg name=\"fs8\" bitsize=\"32\" type=\"ieee_single\"/>\n"
        "  <reg name=\"fs9\" bitsize=\"32\" type=\"ieee_single\"/>\n"
        "  <reg name=\"fs10\" bitsize=\"32\" type=\"ieee_single\"/>\n"
        "  <reg name=\"fs11\" bitsize=\"32\" type=\"ieee_single\"/>\n"
        "  <reg name=\"ft8\" bitsize=\"32\" type=\"ieee_single\"/>\n"
        "  <reg name=\"ft9\" bitsize=\"32\" type=\"ieee_single\"/>\n"
        "  <reg name=\"ft10\" bitsize=\"32\" type=\"ieee_single\"/>\n"
        "  <reg name=\"ft11\" bitsize=\"32\" type=\"ieee_single\"/>\n"
        "</feature>\n",
        32,
    },
    {
        "riscv-64bit-fpu.xml",
        "<?xml version=\"1.0\"?>\n"
        "<!-- Copyright (C) 2018-2019 Free Software Foundation, Inc.\n"
        "\n"
        "     Copying and distribution of this file, with or without modification,\n"
        "     are permitted in any medium without royalty provided the copyright\n"
        "     notice and this notice are preserved.  -->\n"
        "\n"
        "<!DOCTYPE feature SYSTEM \"gdb-target.dtd\">\n"
        "<feature name=\"org.gnu.gdb.riscv.fpu\">\n"
        "\n"
        "  <union id=\"riscv_double\">\n"
        "    <field name=\"float\" type=\"ieee_single\"/>\n"
        "    <field name=\"double\" type=\"ieee_double\"/>\n"
        "  </union>\n"
        "\n"
        "  <reg name=\"ft0\" bitsize=\"64\" type=\"riscv_double\"/>\n"
        "  <reg name=\"ft1\" bitsize=\"64\" type=\"riscv_double\"/>\n"
        "  <reg name=\"ft2\" bitsize=\"64\" type=\"riscv_double\"/>\n"
        "  <reg name=\"ft3\" bitsize=\"64\" type=\"riscv_double\"/>\n"
        "  <reg name=\"ft4\" bitsize=\"64\" type=\"riscv_double\"/>\n"
        "  <reg name=\"ft5\" bitsize=\"64\" type=\"riscv_double\"/>\n"
        "  <reg name=\"ft6\" bitsize=\"64\" type=\"riscv_double\"/>\n"
        "  <reg name=\"ft7\" bitsize=\"64\" type=\"riscv_double\"/>\n"
        "  <reg name=\"fs0\" bitsize=\"64\" type=\"riscv_double\"/>\n"
        "  <reg name=\"fs1\" bitsize=\"64\" type=\"riscv_double\"/>\n"
        "  <reg name=\"fa0\" bitsize=\"64\" type=\"riscv_double\"/>\n"
        "  <reg name=\"fa1\" bitsize=\"64\" type=\"riscv_double\"/>\n"
        "  <reg name=\"fa2\" bitsize=\"64\" type=\"riscv_double\"/>\n"
        "  <reg name=\"fa3\" bitsize=\"64\" type=\"riscv_double\"/>\n"
        "  <reg name=\"fa4\" bitsize=\"64\" type=\"riscv_double\"/>\n"
        "  <reg name=\"fa5\" bitsize=\"64\" type=\"riscv_double\"/>\n"
        "  <reg name=\"fa6\" bitsize=\"64\" type=\"riscv_double\"/>\n"
        "  <reg name=\"fa7\" bitsize=\"64\" type=\"riscv_double\"/>\n"
        "  <reg name=\"fs2\" bitsize=\"64\" type=\"riscv_double\"/>\n"
        "  <reg name=\"fs3\" bitsize=\"64\" type=\"riscv_double\"/>\n"
        "  <reg name=\"fs4\" bitsize=\"64\" type=\"riscv_double\"/>\n"
        "  <reg name=\"fs5\" bitsize=\"64\" type=\"riscv_double\"/>\n"
        "  <reg name=\"fs6\" bitsize=\"64\" type=\"riscv_double\"/>\n"
        "  <reg name=\"fs7\" bitsize=\"64\" type=\"riscv_double\"/>\n"
        "  <reg name=\"fs8\" bitsize=\"64\" type=\"riscv_double\"/>\n"
        "  <reg name=\"fs9\" bitsize=\"64\" type=\"riscv_double\"/>\n"
        "  <reg name=\"fs10\" bitsize=\"64\" type=\"riscv_double\"/>\n"
        "  <reg name=\"fs11\" bitsize=\"64\" type=\"riscv_double\"/>\n"
        "  <reg name=\"ft8\" bitsize=\"64\" type=\"riscv_double\"/>\n"
        "  <reg name=\"ft9\" bitsize=\"64\" type=\"riscv_double\"/>\n"
        "  <reg name=\"ft10\" bitsize=\"64\" type=\"riscv_double\"/>\n"
        "  <reg name=\"ft11\" bitsize=\"64\" type=\"riscv_double\"/>\n"
        "</feature>\n",
        32,
    },
    {
        "riscv-32bit-virtual.xml",
        "<?xml version=\"1.0\"?>\n"
        "<!-- Copyright (C) 2018-2019 Free Software Foundation, Inc.\n"
        "\n"
        "     Copying and distribution of this file, with or without modification,\n"
        "     are permitted in any medium without royalty provided the copyright\n"
        "     notice and this notice are preserved.  -->\n"
        "\n"
        "<!DOCTYPE feature SYSTEM \"gdb-target.dtd\">\n"
        "<feature name=\"org.gnu.gdb.riscv.virtual\">\n"
        "  <reg name=\"priv\" bitsize=\"32\"/>\n"
        "</feature>\n",
        1,
    },
    { NULL }
};
