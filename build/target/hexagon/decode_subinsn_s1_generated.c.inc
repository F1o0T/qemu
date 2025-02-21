/* This file is autogenerated by scripts/decodetree.py.  */

typedef struct {
    int Rs;
    int Rt;
    int ui;
} arg_decode_subinsn_s10;

typedef arg_decode_subinsn_s10 arg_SS1_storew_io;
static bool trans_SS1_storew_io(DisasContext *ctx, arg_SS1_storew_io *a);
typedef arg_decode_subinsn_s10 arg_SS1_storeb_io;
static bool trans_SS1_storeb_io(DisasContext *ctx, arg_SS1_storeb_io *a);

static void decode_subinsn_s1_extract_SS1_storeb_io(DisasContext *ctx, arg_decode_subinsn_s10 *a, uint16_t insn)
{
    a->Rt = decode_mapped_reg_R_16(ctx, extract32(insn, 0, 4));
    a->Rs = decode_mapped_reg_R_16(ctx, extract32(insn, 4, 4));
    a->ui = extract32(insn, 8, 4);
}

static void decode_subinsn_s1_extract_SS1_storew_io(DisasContext *ctx, arg_decode_subinsn_s10 *a, uint16_t insn)
{
    a->Rt = decode_mapped_reg_R_16(ctx, extract32(insn, 0, 4));
    a->Rs = decode_mapped_reg_R_16(ctx, extract32(insn, 4, 4));
    a->ui = extract32(insn, 8, 4);
}

static bool decode_subinsn_s1(DisasContext *ctx, uint16_t insn)
{
    union {
        arg_decode_subinsn_s10 f_decode_subinsn_s10;
    } u;

    switch ((insn >> 12) & 0x1) {
    case 0x0:
        /* ...0.... ........ */
        /* target/hexagon/subinsn_s1_decode_generated:10 */
        decode_subinsn_s1_extract_SS1_storew_io(ctx, &u.f_decode_subinsn_s10, insn);
        if (trans_SS1_storew_io(ctx, &u.f_decode_subinsn_s10)) return true;
        break;
    case 0x1:
        /* ...1.... ........ */
        /* target/hexagon/subinsn_s1_decode_generated:18 */
        decode_subinsn_s1_extract_SS1_storeb_io(ctx, &u.f_decode_subinsn_s10, insn);
        if (trans_SS1_storeb_io(ctx, &u.f_decode_subinsn_s10)) return true;
        break;
    }
    return false;
}
