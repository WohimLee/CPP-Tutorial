


int main()
{

  const char* m_scoring;
  
  switch(m_scoring)
  {
    case L1_NORM: 
      m_scoring_object = new L1Scoring;
      break;
      
    case L2_NORM:
      m_scoring_object = new L2Scoring;
      break;
    
    case CHI_SQUARE:
      m_scoring_object = new ChiSquareScoring;
      break;
      
    case KL:
      m_scoring_object = new KLScoring;
      break;
      
    case BHATTACHARYYA:
      m_scoring_object = new BhattacharyyaScoring;
      break;
      
    case DOT_PRODUCT:
      m_scoring_object = new DotProductScoring;
      break;
    default:
        
  }
}