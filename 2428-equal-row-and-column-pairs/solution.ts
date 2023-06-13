const equalPairs = (grid: number[][]): number => {
  const n = grid.length;
  let count = 0;
  const rowFrequency = new Map<string, number>();

  for (let i = 0; i < n; ++i) {
    const row = grid[i].join('-');
    rowFrequency.set(row, (rowFrequency.get(row) || 0) + 1);
  }

  for (let i = 0; i < n; ++i) {
    const column: number[] = [];

    for (let j = 0; j < n; ++j) {
      column.push(grid[j][i]);
    }
    const columnString = column.join('-');

    if (rowFrequency.has(columnString)) {
      count += rowFrequency.get(columnString);
    }
  }

  return count;
};
