#Function to find if there exists a triplet in the 
    #array A[] which sums up to X.
    def find3Numbers(self,A, n, X):
        A.sort()
        
        for i in range(n-2):
            start=i+1
            end=n-1
            
            while start<end:
                if A[i]+A[start]+A[end]==X:
                    return 1
                elif A[i]+A[start]+A[end]<X:
                    start=start+1
                elif A[i]+A[start]+A[end]>X:
                    end=end-1
        return 0
