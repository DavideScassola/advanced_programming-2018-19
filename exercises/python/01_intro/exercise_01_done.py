def is_palindrome(string_var):     
    '''
    returns True if string_var is palindrome, False otherwise
    '''
    ########################
    return True if len(string_var)<1 else string_var[0]==string_var[-1] and is_palindrome(string_var[1:-1])
    ########################

def histogram_letters(string_var):     
    '''
    count how many times a letter is present in the string_var
    and returns a dict

    '''    
    ########################
    letters = {}
    for c in string_var:
        letters[c] = 0;
        
    for c in string_var:
        letters[c] += 1;
    ########################
    return letters 

def get_most_frequent(list_var):
    '''
    returns a tuple with the most frequent object in the list with the 
    corresponing number
    '''
        
    ########################     
    freq = histogram_letters(list_var)
    max = 0
    object = None
    
    for e in list_var:
        if(freq[e]>max):
            max = freq[e]
            object = e
    ########################
    return (object,max)

def which_duplicates(list_var):
    '''
    return a dict with containing the repeted object and the number of repetitions
    '''
    
    ########################
    freq = histogram_letters(list_var)
    
    for e in list_var:
        if freq[e]<2:
            del freq[e]
                
    ########################
    return freq


def compute_factorial(int_val):
    '''
    returns factorial of a number
    '''
    ########################
    return 1 if int_val<=1 else int_val*(compute_factorial(int_val-1))
    ########################


def is_prime(n): 
    '''
    returns True if int_val is prime, False otherwise
    '''
    ########################
    return ((compute_factorial(n-1))**2)%n!=0
    ##############compute_factorial##########

        

