#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>

int m_letters = 0;
int m_words = 0;
int m_sentences = 0;
int m_score = 0;

int parseText(string strText)
{
    int len = strlen(strText);

    m_letters = 0;

    // count chars first
    int nWordsCount = 0;
    int nSentences = 0;

    for(int i=0; i < len; i++)
    {
        char current_char = strText[i];
        char next_char = strText[i+1];

        // if letter between a-z, A-Z
        if( (current_char >= 'a' && current_char <= 'z') || (current_char >= 'A' && current_char <= 'Z') )
        {
            m_letters += 1;
        }

        // if space found
        if( next_char == ' ' || next_char == '\0' )
        {
            nWordsCount += 1;
        }

        // if dot found
        if( next_char == '.' )
        {
            //m_letters -= 1;
            nSentences += 1;
            //nWordsCount += 1;
        }

        // if exclamation mark found
        if( next_char == '!')
        {
            if( (current_char >= 'a' && current_char <= 'z') || (current_char >= 'A' && current_char <= 'Z') )
                nSentences += 1;
        }

        // if question mark found
        if( next_char == '?')
        {
            if( (current_char >= 'a' && current_char <= 'z') || (current_char >= 'A' && current_char <= 'Z') )
                nSentences += 1;
        }

        // if comma found
        if( current_char == ',' )
        {
            // nothing
        }
    }

    m_words = nWordsCount;
    m_sentences = nSentences;

    //printf("Letters : %d\n", m_letters);
    //printf("Words : %d\n", m_words);
    //printf("Sentences : %d\n", m_sentences);

    double x = m_letters*100/m_words;
    double y = m_sentences*100/m_words;
    double z = (0.0588 * x) - (0.296 * y) - 15.8;

    m_score = round(z);

    if( m_score >= 16 )
    {
        printf("Grade 16+\n");
    } else if( m_score < 1 )
    {
        printf("Before Grade 1\n");
    } else
    {
        printf("Grade %i\n", m_score);
    }

    return 0;
}

int main()
{
    string strUserInput = get_string("Text: ");

    parseText(strUserInput);

    return 0;
}
