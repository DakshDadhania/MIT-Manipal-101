/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Project/Maven2/JavaApp/src/main/java/${packagePath}/${mainClassName}.java to edit this template
 */

package com.mycompany.mavenproject2;

/**
 *
 * @author niraj
 */
public class Mavenproject2 {

    public static void main(String[] args) 
    {
        int a[]={1,2,3,4};
        for(int i=0;i<4;i++) 
        {
         for(int j=0;j<4;j++) 
         {
          for(int k=0;k<4;k++) 
          {
           for (int l=0;l<4;l++) 
           {
             if(a[i]!=a[j]&&a[i]!=a[k]&&a[i]!=a[l]&&a[j]!=a[k]&&a[j]!=a[l]&&a[k]!=a[l])
             System.out.println(a[i]+""+a[j]+""+a[k]+""+a[l]); 
            
           }
          }
         }
        }
    }
}
