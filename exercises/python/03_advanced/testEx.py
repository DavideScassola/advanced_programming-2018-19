__all__ = ['MyRange','myrange']

class MyRange():
          
    def __init__(self, start, stop, step=1):
        self.my = range(start, stop, step)
        
def myrange(*args):
    n_args = len(args)
    if n_args not in [1,2,3]:
        raise TypeError(str(n_args) + " is not a correct number of arguments")
    if n_args==3:   
        return MyRange(args[0],args[1],args[2]).my
    elif n_args==2:
        return MyRange(args[0],args[1]).my
    elif n_args==1:
        return MyRange(0,args[0]).my

import unittest
class TestRanges(unittest.TestCase):
    def test_lower_bounds(self):
        self.assertEqual(0, min([i for i in range(12)]))
        self.assertEqual(0, min([i for i in myrange(2)]))

    def test_upper_bounds(self):
        self.assertEqual(11, max([i for i in range(12)]))
        self.assertEqual(1, max([i for i in myrange(2)]))

    def test_size(self):
        self.assertEqual(10,len([i for i in myrange(1,100,10)]))
        self.assertEqual(10,len([i for i in range(1,100,10)]))

    def test_equivalence(self):
        self.assertEqual([i for i in myrange(1,17,2)], [i for i in range(1,17,2)])


    # def test_MyRange_ctor(self):

if __name__ == '__main__':
	unittest.main()
