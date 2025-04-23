\begin{example}
    在椭球面$4x^2 + y^2 + z^2 = 4$的第一卦限部分上求一点，使得过此点的切平面与坐标平面所围成的体积最小。
\end{example}

\begin{solution}
    设所求点为$(x_0, y_0, z_0)$，则该点处切平面的法向量为$(4x_0, y_0, z_0)$,所求切平面的方程为
    $$
        4x_0(x - x_0) + y_0(y - y_0) + z_0(z - z_0) = 0.
    $$
    即
    $$
        4x_0 x + y_0 y + z_0 z = 4
    $$
    $$
        \text{三棱锥体积}V = \frac{8}{3x_0 y_0 z_0}(x_0,y_0,z_0 > 0)
    $$
    为了求$V$的最小值，我们考虑$x_0y_0z_0$的最大值。这里可以直接使用拉格朗日乘数法。但为了简化计算，我们采用不等式的方式来求解。
    $$
        \begin{split}
        x_0y_0z_0 &= \frac{1}{2}\cdot 2x_0\cdot y_0 \cdot z_0\\
        &\leqslant\frac{1}{2}\left(\frac{4x_0^2 + y_0^2 + z_0^2}{3}\right)^{3/2}\\
        &= \frac{4}{3\sqrt{3}}
        \end{split}
    $$
    当且仅当$x_0 = \dfrac{1}{\sqrt{3}}, y_0 = z_0 = \dfrac{2}{\sqrt{3}}$时取等

    故所求点为$(\dfrac{1}{\sqrt{3}},\dfrac{2}{\sqrt{3}},\dfrac{2}{\sqrt{3}})$
    