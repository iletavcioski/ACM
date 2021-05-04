class BlackBenduday:
  def savings(self, prices, discounts, k):
        arr = []
        for a, b in zip(prices, discounts):
            arr.append(a * b / 100)
        arr.sort(reverse=True)
        return '%.2f' % sum(arr[:k])
if __name__ == '__main__':
    b = BlackBenduday()
    print(b.savings([134,777,207,562,22,966,447,126,73,203], [49,57,95,83,20,43,48,98,16,26], 10))
   