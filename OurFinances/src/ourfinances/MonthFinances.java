package ourfinances;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class MonthFinances implements Serializable
{
    private int month; // месяц
    private int year; // год
    private final ArrayList <Finance> incomes; // доходы
    private final ArrayList <Finance> spending; // расходы
    private double summa_incomes; // сумма доходов
    private double summa_spending; // сумма расходов
    
    MonthFinances(int m, int y)
    {
        this.month = m;
        this.year = y;
        
        this.incomes = new ArrayList<>();
        this.spending = new ArrayList<>();
        
        this.summa_incomes = 0;
        this.summa_spending = 0;
    }
    
    public void addIncome(Finance finance)
    {
        incomes.add(finance);
 
        Comparator <Finance> itemComparator = new Comparator <Finance>()
        {
            @Override
            public int compare(Finance a, Finance b)
            {
            return (int)(b.getValue() - a.getValue());
            }
        };
        Collections.sort(incomes, itemComparator);
    }
    
    public void addSpending(Finance finance)
    {
        spending.add(finance);
        
        Comparator <Finance> itemComparator = new Comparator <Finance>()
        {
            @Override
            public int compare(Finance a, Finance b)
            {
                return (int)(b.getValue() - a.getValue());
            }
        };
        Collections.sort(spending, itemComparator);
    }
    
    public void deleteIncome(int i)
    {
        incomes.remove(i);
    }
    
    public void deleteSpending(int i)
    {
        spending.remove(i);
    }
    
    private void calculateSummaIncomes()
    {
        this.summa_incomes = 0;
        for (Finance income : incomes) 
        {
            this.summa_incomes += income.getValue();
        }    
    }
    
    private void calculateSummaSpending()
    {
        this.summa_spending = 0;
        for (Finance one_spending : spending)
        {
            this.summa_spending += one_spending.getValue();
        }
    }
    
    public double getSummaIncomes()
    {
        calculateSummaIncomes();
        return this.summa_incomes;
    }
    
    public double getSummaSpending()
    {
        calculateSummaSpending();
        return this.summa_spending;
    }
    
    public double getSummaFinances()
    {
        return this.summa_incomes - this.summa_spending;
    }
    
    public ArrayList <Finance> getIncomes()
    {
        return this.incomes;
    }
    
    public ArrayList <Finance> getSpending()
    {
        return this.spending;
    }
    
    public void setMonth(int m)
    {
        this.month = m;
    }
    
    public void setYear(int y)
    {
        this.year = y;
    }
    
    public int getMonth()
    {
        return this.month;
    }
    
    public int getYear()
    {
        return this.year;
    }
   
}
