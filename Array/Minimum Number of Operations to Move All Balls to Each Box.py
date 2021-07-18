class Solution(object):
    def minOperations(self, boxes):
        count = 0
        ans = []
        ball_position = [i for i in range(len(boxes)) if boxes[i]=='1']
        for i in range(len(boxes)):
            ans.append(sum([abs(ball_pos-i) for ball_pos in ball_position]))
        return ans

        