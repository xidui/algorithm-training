func myPow(x float64, n int) float64 {
	flag := n < 0
	N := n
	if flag {
		N = n * -1
	}

	mii := map[int]float64{}
	mii[1] = x

	i := 2;
	for ; i <= N; i = i * 2 {
		mii[i] = mii[i / 2] * mii[i / 2]
	}

	ans := 1.0
	for N != 0 {
		if i > N {
			i = i / 2
			continue
		}
		N = N - i
		ans = ans * mii[i]
	}
	if flag == true {
		return 1 / ans
	}

	return ans
}
