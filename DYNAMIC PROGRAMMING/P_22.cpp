int numOfWays(int n)
{
    if(n==0)
        return 1;
    if(n<0)
        return 0;
    if(m[n]!=-1)
        return m[n];
  if(n>0)  
  {
    m[n] = numOfWays(n-3)+numOfWays(n-5)+numOfWays(n-10);
  }
  return m[n];
}
