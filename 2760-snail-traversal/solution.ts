interface Array<T> {
    snail(rowsCount: number, colsCount: number): number[][];
}


Array.prototype.snail = function (rowsCount: number, colsCount: number): number[][] {
    const nums = this as number[];
    if (rowsCount * colsCount !== nums.length) return [];

    const result: number[][] = Array.from({ length: rowsCount }, () => []);

    let index = 0; 
    for (let col = 0; col < colsCount; ++col) {
        if (col % 2 === 0) {
            for (let row = 0; row < rowsCount; ++row) {
                result[row][col] = nums[index++];
            }
        } else {
            for (let row = rowsCount - 1; row >= 0; --row) {
                result[row][col] = nums[index++];
            }
        }
    }

    return result;
}

/**
 * const arr = [1,2,3,4];
 * arr.snail(1,4); // [[1,2,3,4]]
 */
