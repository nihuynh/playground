from django import forms
    
class Form(forms.Form):
    input = forms.DateField(help_text="Enter a date between now and 4 weeks (default 3).")