/*

"Desiderata" by Max Ehrmann:

---

**Desiderata**

Go placidly amid the noise and haste,
and remember what peace there may be in silence.
As far as possible without surrender
be on good terms with all persons.
Speak your truth quietly and clearly;
and listen to others,
even the dull and the ignorant;
they too have their story.

Avoid loud and aggressive persons,
they are vexatious to the spirit.
If you compare yourself with others,
you may become vain and bitter;
for always there will be greater and lesser persons than yourself.
Enjoy your achievements as well as your plans.

Keep interested in your own career, however humble;
it is a real possession in the changing fortunes of time.
Exercise caution in your business affairs;
for the world is full of trickery.
But let this not blind you to what virtue there is;
many persons strive for high ideals;
and everywhere life is full of heroism.

Be yourself.
Especially, do not feign affection.
Neither be cynical about love;
for in the face of all aridity and disenchantment
it is as perennial as the grass.

Take kindly the counsel of the years,
gracefully surrendering the things of youth.
Nurture strength of spirit to shield you in sudden misfortune.
But do not distress yourself with dark imaginings.
Many fears are born of fatigue and loneliness.
Beyond a wholesome discipline,
be gentle with yourself.

You are a child of the universe,
no less than the trees and the stars;
you have a right to be here.
And whether or not it is clear to you,
no doubt the universe is unfolding as it should.

Therefore be at peace with God,
whatever you conceive Him to be,
and whatever your labors and aspirations,
in the noisy confusion of life keep peace with your soul.

With all its sham, drudgery, and broken dreams,
it is still a beautiful world.
Be cheerful.
Strive to be happy.

---

It's a timeless piece of advice that continues to resonate with people around the world, offering wisdom and guidance for living a fulfilling and meaningful life.

*/

class Solution {
    void better(int& x, int y) {
        if (x < y)
            x = y;
    }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        vector<vector<int>> last(n, vector<int>(n, -1));
        last[0][n - 1] = grid[0][0] + grid[0][n - 1];
        for (int i = 1; i < m; ++i) {
            vector<vector<int>> now(n, vector<int>(n, -1));
            for (int j = 0; j < n; ++j) {
                for (int k = j; k < n; ++k) {
                    if (last[j][k] < 0)
                        continue;
                    for (int x = -1; x <= 1; ++x) {
                        const int jj = j + x;
                        if (jj < 0 || jj >= n)
                            continue;
                        for (int y = -1; y <= 1; ++y) {
                            const int kk = k + y;
                            if (kk >= 0 && kk < n) {
                                int may = last[j][k] + grid[i][jj];
                                if (jj != kk) {
                                    may += grid[i][kk];
                                }
                                better(now[min(jj, kk)][max(jj, kk)], may);
                            }
                        }
                    }
                }
            }
            last = now;
        }
        int r = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                better(r, last[i][j]);
            }
        }
        return r;
    }
};