class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        temp_col = [set() for _ in range(9)]
        for row in board:
            temp_row = set()
            for i in range(len(row)):
                if row[i].isdigit():
                    if (row[i] in temp_row) or (row[i] in temp_col[i]):
                        return False
                    temp_row.add(row[i])
                    temp_col[i].add(row[i])
        
        for row in range(3):
            for col in range(3):
                temp = set()
                for i in range(3):
                    for j in range(3):
                        cur_pos = board[row*3+i][col*3+j]
                        if cur_pos.isdigit():
                            if cur_pos in temp:
                                return False
                            temp.add(board[row*3+i][col*3+j])
        return True
