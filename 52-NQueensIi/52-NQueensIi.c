// Last updated: 2/23/2026, 11:08:16 PM
/**
 * 1行ずつクイーンを置く (各行に置ける数は必ず1つ)
 *
 * 置けるかどうかの判定は3種類でする
 * - colUsed[c] 列cがすでに使われているかどうか
 * - negDiagUsed[idx] 斜め(\) が既に使われてるか
 * - posDiagUsed[idx] 斜め(/) が既に使われてるか
 *
 * 対角線の添字
 * - negDiagは、同じ数字になる時はr-c つまり n=4のとき -3~3
 *   0からにしたいからずらして、0~2n-2
 * - posDiagは、同様に r+cでよくて、負の数はないからそのまま使う 0~2n-2
 */
typedef struct {
    int n;             // 盤面のサイズ
    int cnt;           // 見つけた解の数
    bool* colUsed;     // 列cの使用状況
    bool* negDiagUsed; // (\)対角線の使用状況 (r-c) + (n-1)
    bool* posDiagUsed; // (/)対角線の使用状況 (r+c)
} NQueenCtx;

static void freeAll(NQueenCtx* ctx) {
    free(ctx->colUsed);
    free(ctx->negDiagUsed);
    free(ctx->posDiagUsed);
}

static void dfs(NQueenCtx* ctx, int r) {
    // r == ctx.n となったら再帰終わり
    if (r == ctx->n) {
        ctx->cnt++;
        return;
    }

    // r行におけるcを試す 全探索
    for (int c = 0; c < ctx->n; c++) {
        size_t negIdx = (r - c) + (ctx->n - 1);
        size_t posIdx = r + c;

        // すでに置いてるかをチェックする
        if (ctx->colUsed[c] || ctx->negDiagUsed[negIdx] || ctx->posDiagUsed[posIdx]) {
            continue;
        }

        // 置く
        ctx->colUsed[c] = true;
        ctx->negDiagUsed[negIdx] = true;
        ctx->posDiagUsed[posIdx] = true;

        // checkして全てtrueなら、次に行く
        dfs(ctx, r + 1);

        // 置かない(戻る)
        ctx->colUsed[c] = false;
        ctx->negDiagUsed[negIdx] = false;
        ctx->posDiagUsed[posIdx] = false;
    }
}

int totalNQueens(int n) {
    NQueenCtx ctx = {0};
    ctx.n = n;

    ctx.colUsed = calloc(n, sizeof(*ctx.colUsed));
    ctx.negDiagUsed = calloc(2 * n - 1, sizeof(*ctx.negDiagUsed));
    ctx.posDiagUsed = calloc(2 * n - 1, sizeof(*ctx.posDiagUsed));

    if (!ctx.colUsed || !ctx.negDiagUsed || !ctx.posDiagUsed) {
        return (freeAll(&ctx), 0);
    }

    // 一番上から探索開始
    dfs(&ctx, 0);

    freeAll(&ctx);
    return (ctx.cnt);
}